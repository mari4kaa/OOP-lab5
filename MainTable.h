#pragma once
#include "framework.h"
#include "resource2.h"

class MainTable
{
private:
    static HWND hWndDlgTable;
    static HWND hWndDlgMain;
    static int highlightLine;
    static int deleteLine;

public:
    MainTable();
    ~MainTable();

    void OnCreate(HWND, HINSTANCE);
    static HWND getDlgTable();
    static HWND getDlgMain();
    static int getHighlightLine();
    static void setHighlightLine(int);
    void Show();
    static void Add(LPCWSTR);
    static void Clear();
};