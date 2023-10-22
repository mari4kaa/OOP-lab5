#pragma once
#include "framework.h"

class Shape
{
protected:
    long xs1, ys1, xs2, ys2;
    HBRUSH hBrush, hBrushOld;
public:
    virtual ~Shape(void);
    void Set(long x1, long y1, long x2, long y2);
    virtual void Show(HDC) = 0;
};