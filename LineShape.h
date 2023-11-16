#pragma once
#include "shape.h"

class LineShape : virtual public Shape
{
public:
    LineShape(void);
    virtual ~LineShape(void);
    void Show(HDC, BOOL, BOOL);
    void SetColor(HDC, COLORREF);
    LPCWSTR GetName();
    Shape* CreateShape();
};