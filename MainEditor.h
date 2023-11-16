#pragma once
#include "PointShape.h"
#include "LineShape.h"
#include "RectShape.h"
#include "EllipseShape.h"
#include "CubeShape.h"
#include "LineOOShape.h"

#include "ToolBar.h"
#include "Scene.h"

class MainEditor
{
private:
    static MainEditor* p_instance;
    Shape* pshape = NULL;
    MainEditor(void);
    MainEditor(const MainEditor&);
    MainEditor& operator=(MainEditor&);

    HDC hdc;
    PAINTSTRUCT ps;
    HPEN hPenOld, hPen;
    static bool PaintingNow;
    POINT point;

    LPCWSTR shapeName;
    Scene scene;
    static ToolBar Toolbar;
public:
    static MainEditor* getInstance();
    ~MainEditor(void);
    LPCWSTR Start(HWND, Shape*, int);
    void OnLBdown(HWND);
    LPCWSTR OnLBup(HWND);
    void OnMouseMove(HWND);
    void OnPaint(HWND, int);
    void OnDeleteShape(int);

    void OnCreate(HWND, HINSTANCE);
    void OnSize(HWND);
    void OnNotify(HWND, LPARAM);
};
