#include <windows.h>
#include "WindowParameters.h"
#include <cstdio>

// Forward declaration of WndProc
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// Function to fill the window with a white background
void fillWindowWithWhite(HWND hWnd);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  // Create a window
  WNDCLASS wc = {0};
  wc.lpfnWndProc = WndProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = "MyWindowClass";
  RegisterClass(&wc);

  // Create a window instance
  WindowParameters windowParams; // Create an instance of the WindowParameters class
  HWND hWnd = CreateWindow("MyWindowClass", "My Window", WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, CW_USEDEFAULT, windowParams.returnX(), windowParams.returnY(), NULL, NULL, hInstance, NULL);

  // Show the window
  ShowWindow(hWnd, nCmdShow);

  
  // Run the message loop
  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
  switch (message) 
  {
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    case WM_SIZE:
      MessageBoxW(hWnd, L"Display resolution changed!", L"Info", MB_OK | MB_ICONINFORMATION);
      break;
    case WM_PAINT:
      fillWindowWithWhite(hWnd);
      break;
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}

void fillWindowWithWhite(HWND hWnd)
{
  PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    RECT clientRect;
    GetClientRect(hWnd, &clientRect);

    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255)); // White color
    FillRect(hdc, &clientRect, hBrush);

    EndPaint(hWnd, &ps);
    DeleteObject(hBrush);
}