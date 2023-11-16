#pragma once
#include "framework.h"
#include "resource2.h"
#include <fstream>

class MainTable
{
private:
    static MainTable* p_instance;
    MainTable();
    MainTable(const MainTable&);
    MainTable& operator=(MainTable&);

    static HWND hWndDlgTable;
    static HWND hWndDlgMain;
    static int highlightLine;
    static int deleteLine;

    FILE* fin;
    LPCSTR fileName = "ShapesTable.txt";

public:
    static MainTable* getInstance();
    ~MainTable();

    void OnCreate(HWND, HINSTANCE);
    static HWND getDlgTable();
    static HWND getDlgMain();
    static int getHighlightLine();
    static void setHighlightLine(int);
    void Show();
    void Add(LPCWSTR);
};