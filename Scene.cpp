#include "Scene.h"

Scene::Scene(void) 
{
    fopen_s(&fout, fileName, "w");
    if (fout)
    {
        LPCWSTR fieldsNames = L"SHAPE\t\tx1\ty1\tx2\ty2\n";
        fwprintf(fout, fieldsNames);
        fflush(fout);
    }
};

Scene::~Scene(void)
{
    for (auto shape : ShapeList)
    {
        delete shape;
    }
    if (fout) fclose(fout);
}

void Scene::PushShape(Shape* shape)
{
    currentShape = shape;
    ShapeList.push_back(shape);

    WCHAR coordsString[64];

    if (fout)
    {
        FormString(coordsString);
        fwprintf(fout, coordsString);
        fflush(fout);
    }
}

void Scene::FormString(WCHAR* coordsString)
{
    long xs1 = currentShape->xs1;
    long ys1 = currentShape->ys1;
    long xs2 = currentShape->xs2;
    long ys2 = currentShape->ys2;

    LPCWSTR shapeName = currentShape->GetName();
    LPCWSTR pattern;

    if (wcslen(shapeName) >= 8)
    {
        pattern = L"%s\t%ld\t%ld\t%ld\t%ld\n";
    }
    else
    {
        pattern = L"%s\t\t%ld\t%ld\t%ld\t%ld\n";
    }

    swprintf_s(coordsString, 64, pattern, shapeName, xs1, ys1, xs2, ys2);
}

Shape* Scene::GetLastShape()
{
    return ShapeList.back();
}

void Scene::Show(HDC hdc, BOOL PaintingNow, int selectedLine)
{
    int idx = 0;
    for (auto shape : ShapeList)
    {
        BOOL isSelected = (selectedLine == idx);
        shape->Show(hdc, PaintingNow, isSelected);
        idx++;
    }
}

void Scene::DeleteShape(int shapeNum)
{
    if (shapeNum >= 0 && shapeNum < ShapeList.size())
    {
        auto shapeIter = std::next(ShapeList.begin(), shapeNum);
        ShapeList.erase(shapeIter);
    }
}