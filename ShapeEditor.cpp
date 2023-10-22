#include "ShapeEditor.h"

ShapeEditor::ShapeEditor(void) {};
ShapeEditor::~ShapeEditor(void) {};
bool ShapeEditor::PaintingNow = FALSE;
Scene ShapeEditor::scene;

void ShapeEditor::OnPaint(HWND hWnd)
{
    PAINTSTRUCT ps;
    HDC hdc;
    hdc = BeginPaint(hWnd, &ps);
    scene.Show(hdc);
    EndPaint(hWnd, &ps);
}

void ShapeEditor::OnLBdown(HWND hWnd)
{
    PaintingNow = TRUE;
    GetCursorPos(&point);
    ScreenToClient(hWnd, &point);
    xs1 = point.x;
    ys1 = point.y;
    xs2 = point.x;
    ys2 = point.y;
}
