#include "MainEditor.h"

ToolBar MainEditor::Toolbar;
bool MainEditor::PaintingNow = FALSE;

MainEditor::MainEditor(void) {};

MainEditor* MainEditor::p_instance = 0;
MainEditor* MainEditor::getInstance()
{
    if (!p_instance)
    {
        p_instance = new MainEditor();
    }
    return p_instance;
}

MainEditor::~MainEditor(void)
{
    if (pshape) delete pshape;
};

LPCWSTR MainEditor::Start(HWND hWnd, Shape* shape, int ID_TOOL)
{
    if (pshape) delete pshape;
    pshape = shape;

    shapeName = pshape->GetName();
    SetWindowText(hWnd, shapeName);
    Toolbar.OnToolMove(hWnd, ID_TOOL);

    return L"SHAPE\t\tx1\ty1\tx2\ty2\n";
};

void MainEditor::OnLBdown(HWND hWnd)
{
    if (pshape)
    {
        PaintingNow = TRUE;
        GetCursorPos(&point);
        ScreenToClient(hWnd, &point);

        pshape = pshape->CreateShape();
        pshape->SetAll(point.x, point.y, point.x, point.y);
    }
};

LPCWSTR MainEditor::OnLBup(HWND hWnd)
{
    WCHAR coordsString[64];
    if (pshape)
    {
        PaintingNow = FALSE;
        GetCursorPos(&point);
        ScreenToClient(hWnd, &point);

        pshape->SetEnd(point.x, point.y);
        scene.PushShape(pshape);
        scene.FormString(coordsString);

        pshape = pshape->CreateShape();
        InvalidateRect(hWnd, NULL, TRUE);
    }
    return coordsString;
};

void MainEditor::OnMouseMove(HWND hWnd)
{
    if (pshape && PaintingNow)
    {
        pshape->hdc = GetDC(hWnd);
        SetROP2(pshape->hdc, R2_NOTXORPEN);
        pshape->hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
        pshape->hPenOld = (HPEN)SelectObject(pshape->hdc, pshape->hPen);

        pshape->Show(pshape->hdc, PaintingNow, FALSE);

        GetCursorPos(&point);
        ScreenToClient(hWnd, &point);
        pshape->SetEnd(point.x, point.y);

        pshape->Show(pshape->hdc, PaintingNow, FALSE);

        SelectObject(pshape->hdc, pshape->hPenOld);
        DeleteObject(pshape->hPen);
        ReleaseDC(hWnd, pshape->hdc);
    }
};

void MainEditor::OnPaint(HWND hWnd, int selectedLine)
{
    hdc = BeginPaint(hWnd, &ps);
    scene.Show(hdc, PaintingNow, selectedLine);
    EndPaint(hWnd, &ps);
};

void MainEditor::OnDeleteShape(int selectedLine)
{
    scene.DeleteShape(selectedLine);
}

void MainEditor::OnCreate(HWND hWnd, HINSTANCE hInst)
{
    Toolbar.OnCreate(hWnd, hInst);
};

void MainEditor::OnSize(HWND hWnd)
{
    Toolbar.OnSize(hWnd);
};

void MainEditor::OnNotify(HWND hWnd, LPARAM lParam)
{

    Toolbar.OnNotify(hWnd, lParam);
};
