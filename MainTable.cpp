#include "MainTable.h"
//when mouse is up outside the window, shape isn't displayed but it is in the array of shapes

HWND MainTable::hWndDlgMain = NULL;
HWND MainTable::hWndDlgTable = NULL;
int MainTable::highlightLine = 0;
int MainTable::deleteLine = 0;

MainTable* MainTable::p_instance = 0;

MainTable::MainTable() {};

MainTable* MainTable::getInstance()
{
    if (!p_instance)
        p_instance = new MainTable();
    return p_instance;
};

MainTable::~MainTable() {};

void MainTable::Show()
{
    ShowWindow(hWndDlgTable, SW_SHOW);
};

void MainTable::Add(LPCWSTR coordsString)
{
   SendMessage(GetDlgItem(hWndDlgTable, IDC_LIST1), LB_ADDSTRING, 0, (LPARAM)coordsString);
};

BOOL CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    HWND hWndDlgTable = MainTable::getDlgTable();
    HWND hWndDlgMain = MainTable::getDlgMain();

    switch (message)
    {
    case WM_INITDIALOG:
        return TRUE;

    case WM_SYSCOMMAND:
        if (wParam == SC_CLOSE) ShowWindow(hWndDlgTable, SW_HIDE);
        break;

    case WM_COMMAND:

        if (LOWORD(wParam) == LBN_SELCHANGE)
        {
            int selectedLine = SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETCURSEL, 0, 0);

            PostMessage(hWndDlgMain, WM_TO_HIGHLIGHT_SHAPE, selectedLine, 0);
        }

        if (HIWORD(wParam) == LBN_DBLCLK)
        {
            int selectedLine = (int)SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETCURSEL, 0, 0);
            if(selectedLine != 0) SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_DELETESTRING, selectedLine, 0);

            PostMessage(hWndDlgMain, WM_TO_DELETE_SHAPE, selectedLine, 0);
        }

        if (LOWORD(wParam) == IDCANCEL)
        {
            PostMessage(hWndDlgMain, WM_TO_HIGHLIGHT_SHAPE, 0, 0);
        }

        InvalidateRect(hWndDlgMain, NULL, TRUE);
        break;

    case WM_DESTROY:
        ShowWindow(hWndDlgTable, SW_HIDE);
        hWndDlgTable = NULL;
        break;

    break;
    }
    return FALSE;
};

void MainTable::OnCreate(HWND hWnd, HINSTANCE hInst)
{
    if (hWndDlgTable)
    {
        PostMessage(hWndDlgTable, WM_SYSCOMMAND, SC_CLOSE, 0);
        return;
    }
    
    hWndDlgMain = hWnd;
    hWndDlgTable = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DlgProc);
};

HWND MainTable::getDlgTable()
{
    return hWndDlgTable;
};

HWND MainTable::getDlgMain()
{
    return hWndDlgMain;
};

int MainTable::getHighlightLine()
{
    return highlightLine;
};

void MainTable::setHighlightLine(int line)
{
    highlightLine = line;
};
