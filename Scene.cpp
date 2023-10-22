#include "Scene.h"

Shape* Scene::pcshape[MY_SHAPE_ARRAY_SIZE];

Scene::Scene(void) 
{
    idx = 0;
};

Scene::~Scene(void)
{
    for (int i = 0; i < idx; i++)
    {
        delete pcshape[i];
    }
}

void Scene::PushShape(Shape* shape)
{
    pcshape[idx] = shape;
    idx++;
}

void Scene::Show(HDC hdc)
{
    for (int i = 0; i < idx; i++)
    {
        if (pcshape[i]) pcshape[i]->Show(hdc);
    }
}

bool Scene::IsAvailable()
{
    if (idx < MY_SHAPE_ARRAY_SIZE) return TRUE;
    return FALSE;
}

bool Scene::IsPaintable()
{
    if (idx <= MY_SHAPE_ARRAY_SIZE) return TRUE;
    return FALSE;
}