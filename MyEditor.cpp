#include "MyEditor.h"

ToolBar MyEditor::Toolbar;
bool MyEditor::PaintingNow = FALSE;

MyEditor::MyEditor(void) {};

MyEditor::~MyEditor(void) 
{
    if (pshape) delete pshape;
    delete scene;
};

void MyEditor::Start(HWND hWnd, Shape* shape, int ID_TOOL)
{
    pshape = shape;
    shapeName = pshape->GetName();
    SetWindowText(hWnd, shapeName);
    Toolbar.OnToolMove(hWnd, ID_TOOL);
};

void MyEditor::OnLBdown(HWND hWnd)
{
    if (!scene->IsAvailable()) return;
    if (pshape)
    {
        PaintingNow = TRUE;
        GetCursorPos(&point);
        ScreenToClient(hWnd, &point);
        pshape = pshape->CreateShape();
        pshape->SetAll(point.x, point.y, point.x, point.y);
        scene->PushShape(pshape);
    }
};

void MyEditor::OnLBup(HWND hWnd)
{
    if (!scene->IsAvailable()) return;
    if (pshape)
    {
        GetCursorPos(&point);
        ScreenToClient(hWnd, &point);
        scene->GetLastShape()->SetEnd(point.x, point.y);
        PaintingNow = FALSE;
        InvalidateRect(hWnd, NULL, TRUE);
    }
};

void MyEditor::OnMouseMove(HWND hWnd)
{
    if (!scene->IsAvailable()) return;
    if (pshape && PaintingNow)
    {
        scene->GetLastShape()->PaintRubberMark(hWnd);

        GetCursorPos(&point);
        ScreenToClient(hWnd, &point);
        scene->GetLastShape()->SetEnd(point.x, point.y);

        scene->GetLastShape()->PaintRubberMark(hWnd);
    }
};

void MyEditor::OnPaint(HWND hWnd)
{
    hdc = BeginPaint(hWnd, &ps);
    if (!scene->IsPaintable()) return;
    scene->Show(hdc);
    EndPaint(hWnd, &ps);
};

void MyEditor::OnCreate(HWND hWnd, HINSTANCE hInst)
{
    Toolbar.OnCreate(hWnd, hInst);
};

void MyEditor::OnSize(HWND hWnd)
{
    Toolbar.OnSize(hWnd);
};

void MyEditor::OnNotify(HWND hWnd, LPARAM lParam)
{

    Toolbar.OnNotify(hWnd, lParam, shapeName);
};
