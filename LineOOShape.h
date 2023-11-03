#pragma once
#include "LineShape.h"
#include "EllipseShape.h"
#include "math.h"

class LineOOShape : public LineShape, public EllipseShape
{
private:
    int ellipse_rad = 10;
public:
    LineOOShape(void);
    ~LineOOShape(void);
    void Show(HDC);
    void PaintRubberMark(HWND);
    LPCWSTR GetName();
    Shape* CreateShape();
};