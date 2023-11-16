#pragma once
#include "shape.h"
#include <list>
#include <fstream>

class Scene
{
private:
    std::list<Shape*> ShapeList;
    LPCSTR fileName = "ShapesTable.txt";
    FILE* fout;
    Shape* currentShape = NULL;
public:
    Scene(void);
    ~Scene(void);
    void PushShape(Shape*);
    void DeleteShape(int);
    Shape* GetLastShape();
    void Show(HDC, BOOL, int);
    void FormString(WCHAR*);
};