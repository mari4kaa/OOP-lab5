#include "resource.h"
#include "RectEditor.h"
#include "RectShape.h"

RectEditor::~RectEditor(void) {};

void RectEditor::OnLBup(HWND hWnd)
{
    PaintingNow = FALSE;
    Shape* p_currentShape = new RectShape;

    GetCursorPos(&point);
    ScreenToClient(hWnd, &point);
    xs2 = point.x;
    ys2 = point.y;
    xs1 = (xs1 * 2) - xs2;
    ys1 = (ys1 * 2) - ys2;
    p_currentShape->Set(xs1, ys1, xs2, ys2);

    scene.PushShape(p_currentShape);

    InvalidateRect(hWnd, NULL, TRUE);
};

void RectEditor::OnMouseMove(HWND hWnd)
{
    if (PaintingNow)
    {
        hdc = GetDC(hWnd);
        SetROP2(hdc, R2_NOTXORPEN);
        hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
        hPenOld = (HPEN)SelectObject(hdc, hPen);

        Rectangle(hdc, (xs1 * 2) - xs2, (ys1 * 2) - ys2, xs2, ys2);

        GetCursorPos(&point);
        ScreenToClient(hWnd, &point);
        xs2 = point.x;
        ys2 = point.y;
        Rectangle(hdc, (xs1 * 2) - xs2, (ys1 * 2) - ys2, xs2, ys2);

        SelectObject(hdc, hPenOld);
        DeleteObject(hPen);
        ReleaseDC(hWnd, hdc);
    }
};
