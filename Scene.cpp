#include "Scene.h"

Scene::Scene(void) {};

Scene::~Scene(void)
{
    for (auto shape : ShapeList)
    {
        delete shape;
    }
    shapeTypes.clear();
};

void Scene::ClearScene()
{
    ShapeList.clear();
};

void Scene::PushShape(Shape* shape)
{
    currentShape = shape;
    ShapeList.push_back(shape);
};

void Scene::FormCurrentString(WCHAR* coordsString)
{
    long xs1 = currentShape->xs1;
    long ys1 = currentShape->ys1;
    long xs2 = currentShape->xs2;
    long ys2 = currentShape->ys2;

    LPCWSTR shapeName = currentShape->GetName();
    LPCWSTR pattern = ChoosePattern(shapeName);

    swprintf_s(coordsString, 64, pattern, shapeName, xs1, ys1, xs2, ys2);
};

Shape* Scene::GetLastShape()
{
    return ShapeList.back();
};

void Scene::Show(HDC hdc, BOOL PaintingNow, int selectedLine)
{
    int idx = 0;
    if (ShapeList.empty()) return;
    for (auto shape : ShapeList)
    {
        if (selectedLine != idx)
        {
            shape->Show(hdc, PaintingNow, FALSE);
        }
        else
        {
            shape->hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
            shape->hPenOld = (HPEN)SelectObject(hdc, shape->hPen);
            shape->hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
            shape->hBrushOld = (HBRUSH)SelectObject(hdc, shape->hBrush);

            shape->Show(hdc, PaintingNow, TRUE);

            SelectObject(hdc, shape->hPenOld);
            DeleteObject(shape->hPen);
            SelectObject(hdc, shape->hBrushOld);
            DeleteObject(shape->hBrush);
        }
        idx++;
    }
};

void Scene::DeleteShape(int shapeNum)
{
    if (shapeNum >= 0 && shapeNum < ShapeList.size())
    {
        auto shapeIter = std::next(ShapeList.begin(), shapeNum);
        ShapeList.erase(shapeIter);
    }
};

void Scene::SaveToFile(LPCWSTR path)
{
    FILE* fout;
    _wfopen_s(&fout, path, L"w");
    if (fout)
    {
        fwprintf(fout, L"SHAPE\t\tx1\ty1\tx2\ty2\n");

        for (auto shape : ShapeList)
        {
            LPCWSTR shapeName = shape->GetName();
            long xs1 = shape->xs1;
            long ys1 = shape->ys1;
            long xs2 = shape->xs2;
            long ys2 = shape->ys2;

            LPCWSTR pattern = ChoosePattern(shapeName);

            fwprintf(fout, pattern, shapeName, xs1, ys1, xs2, ys2);
        }
        fclose(fout);
    }
};

void Scene::OpenFromFile(HWND hWnd, LPCWSTR path, AddFunction tableAdd, ClearFunction tableClear)
{
    FILE* fin;
    _wfopen_s(&fin, path, L"r");
    if (fin)
    {
        ClearScene();
        tableClear();
        InvalidateRect(hWnd, NULL, TRUE);

        tableAdd(L"SHAPE\t\txs1\tys1\txs2\tys2\n");
        WCHAR buf[64];
        while (fgetws(buf, 64, fin))
        {
            WCHAR shapeName[64];
            long xs1, ys1, xs2, ys2;
            if (swscanf_s(buf, L"%s\t\t%ld\t%ld\t%ld\t%ld\n", shapeName, 64, &xs1, &ys1, &xs2, &ys2))
            {
                InitShapeTypesMap();
                const auto& pair = shapeTypes.find(shapeName);
                if (pair != shapeTypes.end())
                {
                    Shape* newShape = pair->second->CreateShape();
                    newShape->SetAll(xs1, ys1, xs2, ys2);
                    PushShape(newShape);
                    tableAdd((LPCWSTR)buf);
                }
            }
        }
        fclose(fin);
    }
};

LPCWSTR Scene::ChoosePattern(LPCWSTR shapeName)
{
    LPCWSTR pattern;

    if (wcslen(shapeName) >= 8)
    {
        pattern = L"%s\t%ld\t%ld\t%ld\t%ld\n";
    }
    else
    {
        pattern = L"%s\t\t%ld\t%ld\t%ld\t%ld\n";
    }
    return pattern;
}

void Scene::InitShapeTypesMap()
{
    shapeTypes[L"Point"] = new PointShape;
    shapeTypes[L"Line"] = new LineShape;
    shapeTypes[L"Rectangle"] = new RectShape;
    shapeTypes[L"Ellipse"] = new EllipseShape;
    shapeTypes[L"Cube"] = new CubeShape;
    shapeTypes[L"LineOO"] = new LineOOShape;
};
