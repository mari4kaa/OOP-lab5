#include "LineOOShape.h"

LineOOShape::LineOOShape() {};
LineOOShape::~LineOOShape() {};

void LineOOShape::Show(HDC hdc)
{
    int x1, y1, x2, y2;
    x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

    LineShape::SetAll(x1, y1, x2, y2);
    LineShape::Show(hdc);

    EllipseShape::SetAll(x1 - ellipse_rad, y1 - ellipse_rad, x1 + ellipse_rad, y1 + ellipse_rad);
    EllipseShape::Show(hdc);

    EllipseShape::SetAll(x2 - ellipse_rad, y2 - ellipse_rad, x2 + ellipse_rad, y2 + ellipse_rad);
    EllipseShape::Show(hdc);

    xs1 = x1;
    ys1 = y1;
    xs2 = x2;
    ys2 = y2;
}

void LineOOShape::PaintRubberMark(HWND hWnd)
{
    int x1, y1, x2, y2;
    x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

    LineShape::SetAll(x1, y1, x2, y2);
    LineShape::PaintRubberMark(hWnd);

    EllipseShape::SetAll(x1 - ellipse_rad, y1 - ellipse_rad, x1 + ellipse_rad, y1 + ellipse_rad);
    EllipseShape::PaintRubberMark(hWnd);

    EllipseShape::SetAll(x2 - ellipse_rad, y2 - ellipse_rad, x2 + ellipse_rad, y2 + ellipse_rad);
    EllipseShape::PaintRubberMark(hWnd);

    xs1 = x1;
    ys1 = y1;
    xs2 = x2;
    ys2 = y2;
}

LPCWSTR LineOOShape::GetName()
{
    return L"LineOO";
}

Shape* LineOOShape::CreateShape()
{
    return new LineOOShape;
}