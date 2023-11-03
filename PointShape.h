#pragma once
#include "shape.h"

class PointShape : virtual public Shape
{
public:
    PointShape(void);
    virtual ~PointShape(void);
    void Show(HDC);
    void PaintRubberMark(HWND);
    LPCWSTR GetName();
    Shape* CreateShape();
};
