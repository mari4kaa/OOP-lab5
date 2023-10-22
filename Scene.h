#pragma once
#include "shape.h"
#include "framework.h"
#define MY_SHAPE_ARRAY_SIZE 113

class Scene
{
private:
    static Shape* pcshape[MY_SHAPE_ARRAY_SIZE];
    int idx;
public:
    Scene(void);
    ~Scene(void);
    void PushShape(Shape*);
    void Show(HDC);
    bool IsAvailable();
    bool IsPaintable();
};