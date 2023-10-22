#pragma once
#include "ShapeEditor.h"

class ShapeObjectsEditor
{
private:
    ShapeEditor *pse = NULL;
public:
    ShapeObjectsEditor(void);
    ~ShapeObjectsEditor(void);
    void StartPointEditor(HWND);
    void StartLineEditor(HWND);
    void StartRectEditor(HWND);
    void StartEllipseEditor(HWND);
    void OnLBdown(HWND);
    void OnLBup(HWND);
    void OnMouseMove(HWND);
    void OnPaint(HWND);
};
