#pragma once
#include "shape.h"
#define MY_SHAPE_ARRAY_SIZE 113

class Scene
{
private:
    Shape** pcshape;
    int idx;
public:
    Scene(void);
    ~Scene(void);
    void PushShape(Shape*);
    Shape* GetLastShape();
    void Show(HDC);
    bool IsAvailable();
    bool IsPaintable();
};