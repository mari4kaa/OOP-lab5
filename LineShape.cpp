#include "LineShape.h"

LineShape::LineShape(void) {};
LineShape::~LineShape(void) {};

void LineShape::Show(HDC hdc, BOOL PaintingNow, BOOL isSelected)
{
    if (!PaintingNow && isSelected) SetColor(hdc, RGB(255, 0, 0));
    MoveToEx(hdc, xs1, ys1, NULL);
    LineTo(hdc, xs2, ys2);

    if (!PaintingNow && isSelected)
    {
        SelectObject(hdc, hPenOld);
        DeleteObject(hPen);
    }
}

LPCWSTR LineShape::GetName()
{
    return L"Line";
}

void LineShape::SetColor(HDC hdc, COLORREF selectedColor)
{
    hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    hPenOld = (HPEN)SelectObject(hdc, hPen);
}

Shape* LineShape::CreateShape()
{
    return new LineShape;
}