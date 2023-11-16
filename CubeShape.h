#pragma once
#include "LineShape.h"
#include "RectShape.h"

class CubeShape : public LineShape, public RectShape
{
public:
    CubeShape(void);
    ~CubeShape(void);
    void Show(HDC, BOOL, BOOL);
    void SetColor(HDC, COLORREF) {};
    LPCWSTR GetName();
    Shape* CreateShape();
};