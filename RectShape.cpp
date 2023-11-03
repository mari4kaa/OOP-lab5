#include "RectShape.h"

RectShape::RectShape(void) {};
RectShape::~RectShape(void) {};

void RectShape::Show(HDC hdc)
{
    int xstart = (xs1 * 2) - xs2;
    int ystart = (ys1 * 2) - ys2;
    MoveToEx(hdc, xstart, ystart, NULL);
    LineTo(hdc, xs2, ystart);
    LineTo(hdc, xs2, ys2);
    LineTo(hdc, xstart, ys2);
    LineTo(hdc, xstart, ystart);
}

void RectShape::PaintRubberMark(HWND hWnd)
{
    hdc = GetDC(hWnd);
    SetROP2(hdc, R2_NOTXORPEN);
    hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
    hPenOld = (HPEN)SelectObject(hdc, hPen);

    Rectangle(hdc, (xs1 * 2) - xs2, (ys1 * 2) - ys2, xs2, ys2);

    SelectObject(hdc, hPenOld);
    DeleteObject(hPen);
    ReleaseDC(hWnd, hdc);
}

LPCWSTR RectShape::GetName()
{
    return L"Rectangle";
}

Shape* RectShape::CreateShape()
{
    return new RectShape;
}
