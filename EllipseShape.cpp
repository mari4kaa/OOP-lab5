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
