#include "PointShape.h"

PointShape::PointShape(void) {};
PointShape::~PointShape(void) {};

void PointShape::Show(HDC hdc)
{
    SetPixel(hdc, xs2, ys2, RGB(0, 0, 0));
};
