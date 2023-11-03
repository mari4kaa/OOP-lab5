#pragma once
#include "shape.h"

class LineShape : virtual public Shape
{
public:
    LineShape(void);
    virtual ~LineShape(void);
    void Show(HDC);
    void PaintRubberMark(HWND);
    LPCWSTR GetName();
    Shape* CreateShape();
};