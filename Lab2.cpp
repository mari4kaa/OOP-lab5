﻿// Lab2.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Lab2.h"
#include "MainEditor.h"
#include "MainTable.h"
#include "commdlg.h"


MainEditor* Editor = NULL;
MainTable* Table = NULL;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
LPWSTR getFilename(WCHAR* szFileName, bool forSaving);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB2));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


//   PURPOSE: Saves instance handle and creates main window

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;
    switch (message)
    {
    case WM_CREATE:
    {
        Editor = MainEditor::getInstance();
        Table = new MainTable;

        Table->OnCreate(hWnd, hInst);
        Editor->OnCreate(hWnd, hInst, Table->Add);
        Editor->Start(hWnd, new PointShape, ID_TOOL_POINT);
        break;
    }
    case WM_SIZE:
        Editor->OnSize(hWnd);
        break;
    case WM_NOTIFY:
        Editor->OnNotify(hWnd, lParam);
        break;
    case WM_LBUTTONDOWN:
        Editor->OnLBdown(hWnd);
        break;
    case WM_LBUTTONUP:
    {
        Editor->OnLBup(hWnd, Table->Add);
        break;
    }
    case WM_MOUSEMOVE:
        Editor->OnMouseMove(hWnd);
        break;
    case WM_TO_HIGHLIGHT_SHAPE:
    case WM_PAINT:
        if (!wParam) wParam = 0;
        Editor->OnPaint(hWnd, wParam - 1);
        break;
    case WM_TO_DELETE_SHAPE:
        if (!wParam) wParam = 0;
        Editor->OnDeleteShape(wParam - 1);
        break;
    case WM_COMMAND:
        {
            wmId = LOWORD(wParam);
            wmEvent = HIWORD(wParam);
            switch (wmId)
            {

            case IDM_TABLE:
                Table->Show();
                break;
            case ID_FILE_SAVEASTXT:
            {
                WCHAR szFileName[MAX_PATH] = {};
                LPWSTR path = getFilename(szFileName, TRUE);
                if (path)
                {
                    Editor->OnSaveToFile(path);
                }
                break;
            }
            case ID_FILE_OPENSCENE:
            {
                WCHAR szFileName[MAX_PATH] = {};
                LPWSTR path = getFilename(szFileName, FALSE);
                if (path)
                {
                    Editor->OnOpenFile(hWnd, path, Table->Add, Table->Clear);
                }
                break;
            }

            case IDM_POINT:
            case ID_TOOL_POINT:
                Editor->Start(hWnd, new PointShape, ID_TOOL_POINT);
                break;
            case IDM_LINE:
            case ID_TOOL_LINE:
                Editor->Start(hWnd, new LineShape, ID_TOOL_LINE);
                break;
            case IDM_RECT:
            case ID_TOOL_RECT:
                Editor->Start(hWnd, new RectShape, ID_TOOL_RECT);
                break;
            case IDM_ELLIPSE:
            case ID_TOOL_ELLIPSE:
                Editor->Start(hWnd, new EllipseShape, ID_TOOL_ELLIPSE);
                break;
            case IDM_LINEOO:
            case ID_TOOL_LINEOO:
                Editor->Start(hWnd, new LineOOShape, ID_TOOL_LINEOO);
                break;
            case IDM_CUBE:
            case ID_TOOL_CUBE:
                Editor->Start(hWnd, new CubeShape, ID_TOOL_CUBE);
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_DESTROY:
        delete Editor;
        delete Table;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

LPWSTR getFilename(WCHAR* szFileName, bool forSaving)
{
    OPENFILENAME ofn;

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = (LPCWSTR)L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = (LPWSTR)szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = (LPCWSTR)L"txt";

    forSaving? GetSaveFileName(&ofn) : GetOpenFileName(&ofn);
    return szFileName;
}