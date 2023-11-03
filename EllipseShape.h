#pragma once
#include "shape.h"

class EllipseShape : virtual public Shape
{
public:
    EllipseShape(void);
    virtual ~EllipseShape(void);
    void Show(HDC);
    void PaintRubberMark(HWND);
    LPCWSTR GetName();
    Shape* CreateShape();
};