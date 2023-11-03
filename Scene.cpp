#include "Scene.h"

Scene::Scene(void) 
{
    pcshape = new Shape* [MY_SHAPE_ARRAY_SIZE];
    ZeroMemory(pcshape, MY_SHAPE_ARRAY_SIZE * sizeof(Shape*));
    idx = 0;
};

Scene::~Scene(void)
{
    for (int i = 0; i < idx; i++)
    {
        delete pcshape[i];
    }
    delete[]pcshape;
}

void Scene::PushShape(Shape* shape)
{
    pcshape[idx] = shape;
    idx++;
}

Shape* Scene::GetLastShape()
{
    return pcshape[idx - 1];
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