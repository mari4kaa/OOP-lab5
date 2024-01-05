#include "resource.h"
#include "PointShape.h"
#include "PointEditor.h"

PointEditor::~PointEditor(void) {};
void PointEditor::OnMouseMove(HWND hWnd) {};

void PointEditor::OnLBup(HWND hWnd)
{
    PaintingNow = FALSE;
    Shape* p_currentShape = new PointShape;
    GetCursorPos(&point);
    ScreenToClient(hWnd, &point);
    xs2 = point.x;
    ys2 = point.y;
    p_currentShape->Set(xs1, ys1, xs2, ys2);

    scene.PushShape(p_currentShape);

    InvalidateRect(hWnd, NULL, TRUE);
};
