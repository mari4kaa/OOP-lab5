#include "RectShape.h"

RectShape::RectShape(void) {};
RectShape::~RectShape(void) {};

void RectShape::Show(HDC hdc)
{
    MoveToEx(hdc, xs1, ys1, NULL);
    LineTo(hdc, xs2, ys1);
    LineTo(hdc, xs2, ys2);
    LineTo(hdc, xs1, ys2);
    LineTo(hdc, xs1, ys1);
}