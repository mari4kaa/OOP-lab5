#include "RectShape.h"

RectShape::RectShape(void) {};
RectShape::~RectShape(void) {};

void RectShape::Show(HDC hdc, BOOL PaintingNow, BOOL isSelected)
{
    long xstart = (xs1 * 2) - xs2;
    long ystart = (ys1 * 2) - ys2;
    MoveToEx(hdc, xstart, ystart, NULL);
    LineTo(hdc, xs2, ystart);
    LineTo(hdc, xs2, ys2);
    LineTo(hdc, xstart, ys2);
    LineTo(hdc, xstart, ystart);
};

LPCWSTR RectShape::GetName()
{
    return L"Rectangle";
};

Shape* RectShape::CreateShape()
{
    return new RectShape;
};
