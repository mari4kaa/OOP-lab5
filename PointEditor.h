#pragma once
#include "ShapeEditor.h"

class PointEditor : public ShapeEditor
{
public:
    ~PointEditor(void);
private:
    void OnLBup(HWND);
    void OnMouseMove(HWND);
};