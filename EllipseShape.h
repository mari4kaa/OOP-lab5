#pragma once
#include "shape.h"

class EllipseShape : virtual public Shape
{
private:
    COLORREF brushColor = RGB(255, 255, 0);
public:
    EllipseShape(void);
    virtual ~EllipseShape(void);
    void Show(HDC, BOOL, BOOL);
    void SetColor(HDC, COLORREF);
    LPCWSTR GetName();
    Shape* CreateShape();
};
