#include "MainTable.h"

HWND MainTable::hWndDlgMain = NULL;
HWND MainTable::hWndDlgTable = NULL;
int MainTable::highlightLine = 0;
int MainTable::deleteLine = 0;

MainTable::MainTable() {};
MainTable::~MainTable(){};

void MainTable::Show()
{
    ShowWindow(hWndDlgTable, SW_SHOW);
};

void MainTable::Add(LPCWSTR coordsString)
{
   SendMessage(GetDlgItem(hWndDlgTable, IDC_LIST1), LB_ADDSTRING, 0, (LPARAM)coordsString);
};

void MainTable::Clear()
{
    SendMessage(GetDlgItem(hWndDlgTable, IDC_LIST1), LB_RESETCONTENT, 0, 0);
}

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

        if (HIWORD(wParam) == LBN_SELCHANGE)
        {
            int selectedLine = SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETCURSEL, 0, 0);

            PostMessage(hWndDlgMain, WM_TO_HIGHLIGHT_SHAPE, selectedLine, 0);
            InvalidateRect(hWndDlgMain, NULL, TRUE);
        }

        if (HIWORD(wParam) == LBN_DBLCLK)
        {
            int selectedLine = (int)SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETCURSEL, 0, 0);
            if(selectedLine != 0) SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_DELETESTRING, selectedLine, 0);

            PostMessage(hWndDlgMain, WM_TO_DELETE_SHAPE, selectedLine, 0);
            InvalidateRect(hWndDlgMain, NULL, TRUE);
        }

        if (LOWORD(wParam) == IDCANCEL)
        {
            ShowWindow(hWndDlgTable, SW_HIDE);
            PostMessage(hWndDlgMain, WM_TO_DELETE_SHAPE, 0, 0);
            InvalidateRect(hWndDlgMain, NULL, TRUE);
        }

        break;

    case WM_DESTROY:
        DestroyWindow(hDlg);
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
