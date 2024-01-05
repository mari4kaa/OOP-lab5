#include "LineShape.h"

LineShape::LineShape(void) {};
LineShape::~LineShape(void) {};

void LineShape::Show(HDC hdc, BOOL PaintingNow, BOOL isSelected)
{
    MoveToEx(hdc, xs1, ys1, NULL);
    LineTo(hdc, xs2, ys2);
};

LPCWSTR LineShape::GetName()
{
    return L"Line";
};

Shape* LineShape::CreateShape()
{
    return new LineShape;
};
