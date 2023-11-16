#include "PointShape.h"

PointShape::PointShape(void) {};
PointShape::~PointShape(void) {};

void PointShape::Show(HDC hdc, BOOL PaintingNow, BOOL isSelected)
{
    if (!PaintingNow && isSelected) SetColor(hdc, RGB(255, 0, 0));
    SetPixel(hdc, xs2, ys2, color);
    SetPixel(hdc, xs2 + 1, ys2, color);
    SetPixel(hdc, xs2, ys2 + 1, color);
    SetPixel(hdc, xs2 + 1, ys2 + 1, color);

    color = RGB(0, 0, 0);
};

void PointShape::SetColor(HDC hdc, COLORREF selectedColor)
{
    color = selectedColor;
};

LPCWSTR PointShape::GetName()
{
    return L"Point";
};

Shape* PointShape::CreateShape()
{
    return new PointShape;
};