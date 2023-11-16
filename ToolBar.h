#pragma once

#define IDC_MY_TOOLBAR 1
#define ID_TOOL_POINT 1
#define ID_TOOL_LINE 2
#define ID_TOOL_RECT 3
#define ID_TOOL_ELLIPSE 4
#define ID_TOOL_LINEOO 5
#define ID_TOOL_CUBE 6

class ToolBar
{
private:
    int oldButton = 0;
    HWND hwndToolBar = NULL;
public:
    ToolBar(void);
    void OnCreate(HWND, HINSTANCE);
    void OnSize(HWND);
    void OnToolMove(HWND, int);
    void OnNotify(HWND, LPARAM);
};