#pragma once
#include "shape.h"
#include "PointShape.h"
#include "LineShape.h"
#include "RectShape.h"
#include "EllipseShape.h"
#include "CubeShape.h"
#include "LineOOShape.h"

#include <list>
#include <map>
#include <fstream>

typedef void (*AddFunction)(LPCWSTR);
typedef void (*ClearFunction)();

class Scene
{
private:
    std::list<Shape*> ShapeList;
    std::map<std::wstring, Shape*> shapeTypes;
    Shape* currentShape = NULL;
public:
    Scene(void);
    ~Scene(void);
    void ClearScene();
    void InitShapeTypesMap();
    void PushShape(Shape*);
    void DeleteShape(int);
    Shape* GetLastShape();
    void Show(HDC, BOOL, int);

    void FormCurrentString(WCHAR*);
    LPCWSTR ChoosePattern(LPCWSTR shapeName);
    void SaveToFile(LPCWSTR);
    void OpenFromFile(HWND hWnd, LPCWSTR path, AddFunction tableAdd, ClearFunction tableClear);
};