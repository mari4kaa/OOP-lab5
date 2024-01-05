#include "resource.h"
#include "ToolBar.h"

ToolBar::ToolBar(void) {};

void ToolBar::OnCreate(HWND hWnd, HINSTANCE hInst)
{
    TBBUTTON tbb[6];
    TBADDBITMAP tbab;
    tbab.hInst = HINST_COMMCTRL;
    tbab.nID = IDB_STD_SMALL_COLOR;

    ZeroMemory(tbb, sizeof(tbb));
    tbb[0].iBitmap = 0;
    tbb[0].fsState = TBSTATE_ENABLED;
    tbb[0].fsStyle = TBSTYLE_BUTTON;
    tbb[0].idCommand = ID_TOOL_POINT;
    toolTipsMap[ID_TOOL_POINT] = L"Point";

    tbb[1].iBitmap = 1;
    tbb[1].fsState = TBSTATE_ENABLED;
    tbb[1].fsStyle = TBSTYLE_BUTTON;
    tbb[1].idCommand = ID_TOOL_LINE;
    toolTipsMap[ID_TOOL_LINE] = L"Line";

    tbb[2].iBitmap = 2;
    tbb[2].fsState = TBSTATE_ENABLED;
    tbb[2].fsStyle = TBSTYLE_BUTTON;
    tbb[2].idCommand = ID_TOOL_RECT;
    toolTipsMap[ID_TOOL_RECT] = L"Rectangle";

    tbb[3].iBitmap = 3;
    tbb[3].fsState = TBSTATE_ENABLED;
    tbb[3].fsStyle = TBSTYLE_BUTTON;
    tbb[3].idCommand = ID_TOOL_ELLIPSE;
    toolTipsMap[ID_TOOL_ELLIPSE] = L"Ellipse";

    tbb[4].iBitmap = 4;
    tbb[4].fsState = TBSTATE_ENABLED;
    tbb[4].fsStyle = TBSTYLE_BUTTON;
    tbb[4].idCommand = ID_TOOL_LINEOO;
    toolTipsMap[ID_TOOL_LINEOO] = L"LineOO";

    tbb[5].iBitmap = 5;
    tbb[5].fsState = TBSTATE_ENABLED;
    tbb[5].fsStyle = TBSTYLE_BUTTON;
    tbb[5].idCommand = ID_TOOL_CUBE;
    toolTipsMap[ID_TOOL_CUBE] = L"Cube";

    hwndToolBar = CreateToolbarEx(hWnd,
        WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP | TBSTYLE_TOOLTIPS,
        IDC_MY_TOOLBAR,
        6,
        hInst,
        IDB_BITMAP1,
        tbb,
        6,
        24, 24, 24, 24,
        sizeof(TBBUTTON));
}

void ToolBar::OnSize(HWND hWnd)
{
    RECT rc, rw;
    if (hwndToolBar)
    {
        GetClientRect(hWnd, &rc);
        GetWindowRect(hwndToolBar, &rw);
        MoveWindow(hwndToolBar, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
    }
}

void ToolBar::OnToolMove(HWND hWnd, int ID_TOOL_MOVE)
{
    if (oldButton != 0)
    {
        SendMessage(hwndToolBar, TB_PRESSBUTTON, oldButton, 0);
    }
    SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_MOVE, 1);
    oldButton = ID_TOOL_MOVE;
}

void ToolBar::OnNotify(HWND hWnd, LPARAM lParam)
{
    LPNMHDR pnmh = (LPNMHDR)lParam;
    if (pnmh->code == TTN_NEEDTEXT)
    {
        LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT)lParam;
        if (toolTipsMap[lpttt->hdr.idFrom])
        {
            lstrcpy(lpttt->szText, toolTipsMap[lpttt->hdr.idFrom]);
        }
        else
        {
            lstrcpy(lpttt->szText, L"Unknown");
        }
    }
}