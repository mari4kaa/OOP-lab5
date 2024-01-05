#pragma once

#include "ToolBar.h"
#include "Scene.h"

typedef void (*AddFunction)(LPCWSTR);
typedef void (*ClearFunction)();

class MainEditor
{
private:
    static MainEditor* p_instance;
    MainEditor(void) {};
    MainEditor(const MainEditor&);
    MainEditor& operator=(MainEditor&);

    Shape* pshape = NULL;

    HDC hdc;
    PAINTSTRUCT ps;
    HPEN hPenOld, hPen;
    static bool PaintingNow;
    POINT point;

    Scene scene;
    static ToolBar Toolbar;
public:
    static MainEditor* getInstance();
    ~MainEditor(void);
    void Start(HWND, Shape*, int);
    void OnLBdown(HWND);
    void OnLBup(HWND, AddFunction);
    void OnMouseMove(HWND);
    void OnPaint(HWND, int);
    void OnDeleteShape(int);

    void OnSaveToFile(LPCWSTR path);
    void OnOpenFile(HWND hWnd, LPCWSTR path, AddFunction, ClearFunction);

    void OnCreate(HWND, HINSTANCE, AddFunction);
    void OnSize(HWND);
    void OnNotify(HWND, LPARAM);
};
