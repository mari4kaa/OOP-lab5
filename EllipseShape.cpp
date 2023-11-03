#include "EllipseShape.h"

EllipseShape::EllipseShape(void) {};
EllipseShape::~EllipseShape(void) {};

void EllipseShape::Show(HDC hdc)
{
    hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0));
    hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

    Ellipse(hdc, xs1, ys1, xs2, ys2);

    SelectObject(hdc, hBrushOld);
    DeleteObject(hBrush);
}

void EllipseShape::PaintRubberMark(HWND hWnd)
{
    hdc = GetDC(hWnd);
    SetROP2(hdc, R2_NOTXORPEN);
    hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));
    hPenOld = (HPEN)SelectObject(hdc, hPen);

    Arc(hdc, xs1, ys1, xs2, ys2, 0, 0, 0, 0);

    SelectObject(hdc, hPenOld);
    DeleteObject(hPen);
    ReleaseDC(hWnd, hdc);
}

LPCWSTR EllipseShape::GetName()
{
    return L"Ellipse";
}

Shape* EllipseShape::CreateShape()
{
    return new EllipseShape;
}