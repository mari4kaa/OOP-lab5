#pragma once
#include "ShapeEditor.h"

class LineEditor : public ShapeEditor
{
public:
    ~LineEditor(void);
private:
    void OnLBup(HWND);
    void OnMouseMove(HWND);
};