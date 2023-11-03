#pragma once
#include "shape.h"

class RectShape : virtual public Shape
{
public:
    RectShape(void);
    virtual ~RectShape(void);
    void Show(HDC);
    void PaintRubberMark(HWND);
    LPCWSTR GetName();
    Shape* CreateShape();
};