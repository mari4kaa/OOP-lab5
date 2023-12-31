#pragma once
#include "editor.h"
#include "shape.h"
#include "Scene.h"

class ShapeEditor : public Editor
{
protected:
    static bool PaintingNow;
    POINT point;
    HDC hdc;
    HMENU hMenu, hSubMenu;
    HPEN hPenOld, hPen;
public:
    ShapeEditor(void);
    ~ShapeEditor(void);
    void OnLBdown(HWND);
    virtual void OnLBup(HWND) = 0;
    virtual void OnMouseMove(HWND) = 0;
    void OnPaint(HWND, HDC, PAINTSTRUCT);
    static Scene scene;
};
