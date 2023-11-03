#include "LineShape.h"

LineShape::LineShape(void) {};
LineShape::~LineShape(void) {};

void LineShape::Show(HDC hdc)
{
    MoveToEx(hdc, xs1, ys1, NULL);
    LineTo(hdc, xs2, ys2);
}

void LineShape::PaintRubberMark(HWND hWnd)
{
    hdc = GetDC(hWnd);
    SetROP2(hdc, R2_NOTXORPEN);
    hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
    hPenOld = (HPEN)SelectObject(hdc, hPen);

    MoveToEx(hdc, xs1, ys1, NULL);
    LineTo(hdc, xs2, ys2);

    SelectObject(hdc, hPenOld);
    DeleteObject(hPen);
    ReleaseDC(hWnd, hdc);
}

LPCWSTR LineShape::GetName()
{
    return L"Line";
}

Shape* LineShape::CreateShape()
{
    return new LineShape;
}