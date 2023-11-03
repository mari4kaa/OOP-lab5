#pragma once
#include "framework.h"

class Shape
{
protected:
    long xs1, ys1, xs2, ys2;
    HDC hdc;
    HBRUSH hBrush, hBrushOld;
    HPEN hPenOld, hPen;
public:
    virtual ~Shape(void);
    void SetAll(long x1, long y1, long x2, long y2);
    void SetEnd(long x2, long y2);
    virtual void Show(HDC) = 0;
    virtual void PaintRubberMark(HWND) = 0;
    virtual LPCWSTR GetName() = 0;
    virtual Shape* CreateShape() = 0;
};