#pragma once
#include "PointShape.h"
#include "LineShape.h"
#include "RectShape.h"
#include "EllipseShape.h"
#include "CubeShape.h"
#include "LineOOShape.h"

#include "ToolBar.h"
#include "Scene.h"

class MyEditor
{
private:
    Shape* pshape = NULL;
    HDC hdc;
    PAINTSTRUCT ps;
    HPEN hPenOld, hPen;
    static bool PaintingNow;
    POINT point;

    LPCWSTR shapeName;
    Scene* scene = new Scene;
    static ToolBar Toolbar;
public:
    MyEditor(void);
    ~MyEditor(void);
    void Start(HWND, Shape*, int);
    void OnLBdown(HWND);
    void OnLBup(HWND);
    void OnMouseMove(HWND);
    void OnPaint(HWND);

    void OnCreate(HWND, HINSTANCE);
    void OnSize(HWND);
    void OnNotify(HWND, LPARAM);
};
