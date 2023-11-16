#pragma once
#include "shape.h"

class RectShape : virtual public Shape
{
private:
    long xstart, ystart;
public:
    RectShape(void);
    virtual ~RectShape(void);
    void Show(HDC, BOOL, BOOL);
    void SetColor(HDC, COLORREF);
    LPCWSTR GetName();
    Shape* CreateShape();
};