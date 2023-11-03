#include "resource.h"
#include "CubeShape.h"
#include "CubeEditor.h"

CubeEditor::~CubeEditor(void) {};

void CubeEditor::OnLBup(HWND hWnd)
{
    PaintingNow = FALSE;
    Shape* p_currentShape = reinterpret_cast<Shape*> (new CubeShape);

    GetCursorPos(&point);
    ScreenToClient(hWnd, &point);
    xs2 = point.x;
    ys2 = point.y;
    p_currentShape->Set(xs1, ys1, xs2, ys2);

    scene.PushShape(p_currentShape);

    InvalidateRect(hWnd, NULL, TRUE);
};

void CubeEditor::OnMouseMove(HWND hWnd)
{
    if (PaintingNow)
    {
        hdc = GetDC(hWnd);
        SetROP2(hdc, R2_NOTXORPEN);
        hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
        hPenOld = (HPEN)SelectObject(hdc, hPen);

        //TODO

        SelectObject(hdc, hPenOld);
        DeleteObject(hPen);
        ReleaseDC(hWnd, hdc);
    }
};