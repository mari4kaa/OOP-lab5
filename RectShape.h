#pragma once
#include "shape.h"

class RectShape : public Shape
{
public:
    RectShape(void);
    ~RectShape(void);
    void Show(HDC);
};