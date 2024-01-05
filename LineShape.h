#pragma once
#include "shape.h"

class LineShape : virtual public Shape
{
public:
    LineShape(void);
    virtual ~LineShape(void);
    void Show(HDC, BOOL, BOOL);
    LPCWSTR GetName();
    Shape* CreateShape();
};