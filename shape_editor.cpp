#include "shape_editor.h"
#include "PointEditor.h"
#include "LineEditor.h"
#include "RectEditor.h"
#include "EllipseEditor.h"

ShapeObjectsEditor::ShapeObjectsEditor(void) {};

ShapeObjectsEditor::~ShapeObjectsEditor(void) 
{
    if (pse) delete pse;
};

void ShapeObjectsEditor::StartPointEditor(HWND hWnd)
{
    SetWindowText(hWnd, L"Point");
    if (pse) delete pse;
    pse = new PointEditor;
};

void ShapeObjectsEditor::StartLineEditor(HWND hWnd)
{
    SetWindowText(hWnd, L"Line");
    if (pse) delete pse;
    pse = new LineEditor;
};

void ShapeObjectsEditor::StartRectEditor(HWND hWnd)
{
    SetWindowText(hWnd, L"Rectangle");
    if (pse) delete pse;
    pse = new RectEditor;
};

void ShapeObjectsEditor::StartEllipseEditor(HWND hWnd)
{
    SetWindowText(hWnd, L"Ellipse");
    if (pse) delete pse;
    pse = new EllipseEditor;
};

void ShapeObjectsEditor::OnLBdown(HWND hWnd)
{
    if (!pse->scene.IsAvailable()) return;
    if (pse) pse->OnLBdown(hWnd);
};

void ShapeObjectsEditor::OnLBup(HWND hWnd)
{
    if (!pse->scene.IsAvailable()) return;
    if (pse) pse->OnLBup(hWnd);
};

void ShapeObjectsEditor::OnMouseMove(HWND hWnd)
{
    if (!pse->scene.IsAvailable()) return;
    if (pse) pse->OnMouseMove(hWnd);
};

void ShapeObjectsEditor::OnPaint(HWND hWnd)
{
    if (!pse->scene.IsPaintable()) return;
    if (pse) pse->OnPaint(hWnd);
};
