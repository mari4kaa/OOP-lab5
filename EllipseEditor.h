#pragma once
#include "ShapeEditor.h"

class EllipseEditor : public ShapeEditor
{
public:
    ~EllipseEditor(void);
private:
    void OnLBup(HWND);
    void OnMouseMove(HWND);
};