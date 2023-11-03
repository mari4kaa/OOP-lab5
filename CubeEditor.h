#pragma once
#include "ShapeEditor.h"

class CubeEditor : public ShapeEditor
{
public:
    ~CubeEditor(void);
private:
    void OnLBup(HWND);
    void OnMouseMove(HWND);
};
