#include "ShapeEditor.h"

ShapeEditor::ShapeEditor(void) {};
ShapeEditor::~ShapeEditor(void) {};
bool ShapeEditor::PaintingNow = FALSE;
Scene ShapeEditor::scene;

void ShapeEditor::OnPaint(HWND hWnd, HDC hdc, PAINTSTRUCT ps)
{
    scene.Show(hdc);
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
