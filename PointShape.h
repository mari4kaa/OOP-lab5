#pragma once
#include "shape.h"

class PointShape : public Shape
{
public:
    PointShape(void);
    ~PointShape(void);
    void Show(HDC);
};
