#include "LineShape.h"

LineShape::LineShape(void) {};
LineShape::~LineShape(void) {};

void LineShape::Show(HDC hdc)
{
    MoveToEx(hdc, xs1, ys1, NULL);
    LineTo(hdc, xs2, ys2);
}