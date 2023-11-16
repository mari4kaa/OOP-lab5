#pragma once
#include "shape.h"

class PointShape : virtual public Shape
{
private:
    COLORREF color = RGB(0, 0, 0);
public:
    PointShape(void);
    virtual ~PointShape(void);
    void Show(HDC, BOOL, BOOL);
    void SetColor(HDC, COLORREF);
    LPCWSTR GetName();
    Shape* CreateShape();
};
