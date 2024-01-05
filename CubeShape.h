#pragma once
#include "LineShape.h"
#include "RectShape.h"

class CubeShape : public LineShape, public RectShape
{
public:
    CubeShape(void);
    ~CubeShape(void);
    void Show(HDC, BOOL, BOOL);
    LPCWSTR GetName();
    Shape* CreateShape();
};