#pragma once
#include "framework.h"

class Editor
{
public:
    virtual ~Editor(void) {};
    virtual void OnLBdown(HWND) = 0;
    virtual void OnLBup(HWND) = 0;
    virtual void OnMouseMove(HWND) = 0;
    virtual void OnPaint(HWND, HDC, PAINTSTRUCT) = 0;
};
