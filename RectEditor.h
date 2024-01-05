#pragma once
#include "ShapeEditor.h"

class RectEditor : public ShapeEditor
{
public:
    ~RectEditor(void);
private:
    void OnLBup(HWND);
    void OnMouseMove(HWND);
};