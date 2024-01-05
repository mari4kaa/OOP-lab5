#include "EllipseShape.h"

EllipseShape::EllipseShape(void) {};
EllipseShape::~EllipseShape(void) {};

void EllipseShape::Show(HDC hdc, BOOL PaintingNow, BOOL isSelected)
{
    if (!PaintingNow && !isSelected)
    {
        SetColor(hdc, brushColor);
    }

    Ellipse(hdc, xs1, ys1, xs2, ys2);

    if (!PaintingNow && !isSelected)
    {
        SelectObject(hdc, hBrushOld);
        DeleteObject(hBrush);

        brushColor = RGB(255, 255, 0);
    }
}

void EllipseShape::SetColor(HDC hdc, COLORREF selectedColor)
{
    brushColor = selectedColor;
    hBrush = (HBRUSH)CreateSolidBrush(selectedColor);
    hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
}

LPCWSTR EllipseShape::GetName()
{
    return L"Ellipse";
}

Shape* EllipseShape::CreateShape()
{
    return new EllipseShape;
}