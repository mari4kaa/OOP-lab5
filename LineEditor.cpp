#include "resource.h"
#include "LineShape.h"
#include "LineEditor.h"

LineEditor::~LineEditor(void) {};

void LineEditor::OnLBup(HWND hWnd)
{
    PaintingNow = FALSE;
    Shape* p_currentShape = new LineShape;

    GetCursorPos(&point);
    ScreenToClient(hWnd, &point);
    xs2 = point.x;
    ys2 = point.y;
    p_currentShape->Set(xs1, ys1, xs2, ys2);

    scene.PushShape(p_currentShape);

    InvalidateRect(hWnd, NULL, TRUE);
};

void LineEditor::OnMouseMove(HWND hWnd) 
{
    if (PaintingNow)
    {
        hdc = GetDC(hWnd);
        SetROP2(hdc, R2_NOTXORPEN);
        hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
        hPenOld = (HPEN)SelectObject(hdc, hPen);

        MoveToEx(hdc, xs1, ys1, NULL);
        LineTo(hdc, xs2, ys2);

        GetCursorPos(&point);
        ScreenToClient(hWnd, &point);
        xs2 = point.x;
        ys2 = point.y;

        MoveToEx(hdc, xs1, ys1, NULL);
        LineTo(hdc, xs2, ys2);

        SelectObject(hdc, hPenOld);
        DeleteObject(hPen);
        ReleaseDC(hWnd, hdc);
    }
};

