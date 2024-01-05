#include "resource.h"
#include "EllipseShape.h"
#include "EllipseEditor.h"

EllipseEditor::~EllipseEditor(void) {};

void EllipseEditor::OnLBup(HWND hWnd)
{
    PaintingNow = FALSE;
    Shape* p_currentShape = new EllipseShape;

    GetCursorPos(&point);
    ScreenToClient(hWnd, &point);
    xs2 = point.x;
    ys2 = point.y;
    p_currentShape->Set(xs1, ys1, xs2, ys2);

    scene.PushShape(p_currentShape);

    InvalidateRect(hWnd, NULL, TRUE);
};

void EllipseEditor::OnMouseMove(HWND hWnd)
{
    if (PaintingNow)
    {
        hdc = GetDC(hWnd);
        SetROP2(hdc, R2_NOTXORPEN);
        hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
        hPenOld = (HPEN)SelectObject(hdc, hPen);

        Arc(hdc, xs1, ys1, xs2, ys2, 0, 0, 0, 0);

        GetCursorPos(&point);
        ScreenToClient(hWnd, &point);
        xs2 = point.x;
        ys2 = point.y;
        Arc(hdc, xs1, ys1, xs2, ys2, 0, 0, 0, 0);

        SelectObject(hdc, hPenOld);
        DeleteObject(hPen);
        ReleaseDC(hWnd, hdc);
    }
};