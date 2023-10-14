#include <windows.h>
#include "WindowParameters.h"
#include "..\..\Resources\Config\FirstProgramRun.cpp"
#include <cstdio>

// Forward declaration of WndProc
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// Function to fill the window with a white background
void fillWindowWithWhite(HWND hWnd);
void drawTextOnWindow(HWND hWnd);
void FirstProgramRun::setINIValuesAtStartup();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

  FirstProgramRun::setINIValuesAtStartup();
  // Create a window
  WNDCLASSA wc = {0}; // Use WNDCLASSA for ANSI character strings
  wc.lpfnWndProc = WndProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = "MyWindowClass"; // Regular char string without 'L'
  RegisterClassA(&wc); // Use RegisterClassA for ANSI character strings

  // Create a window instance
  WindowParameters windowParams; // Create an instance of the WindowParameters class
  HWND hWnd = CreateWindowA("MyWindowClass", "My Window", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, // Use CreateWindowA for ANSI character strings
                             CW_USEDEFAULT, CW_USEDEFAULT, windowParams.returnX(), windowParams.returnY(), NULL, NULL, hInstance, NULL);

  // Show the window
  ShowWindow(hWnd, SW_SHOWNORMAL);

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
      MessageBoxA(hWnd, "Display resolution changed!", "Info", MB_OK | MB_ICONINFORMATION); // Use MessageBoxA for ANSI character strings
      break;
    case WM_PAINT:
      drawTextOnWindow(hWnd);
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

void drawTextOnWindow(HWND hWnd) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    // Define the text you want to display
    const char* textToDisplay = "Hello, Windows!"; // Regular char string without 'L'

    RECT clientRect;
    GetClientRect(hWnd, &clientRect);

    // Set text color
    SetTextColor(hdc, RGB(0, 0, 0)); // Black color

    // Create a LOGFONTA structure for the custom font
    LOGFONTA lf = {0}; // Use LOGFONTA for ANSI character strings
    lf.lfHeight = 24;  // Set the desired font size
    strcpy_s(lf.lfFaceName, "Syne-Regular"); // Use the font name without the file extension

    // Create the custom font
    HFONT hFont = CreateFontIndirectA(&lf); // Use CreateFontIndirectA for ANSI character strings

    // Select the custom font into the device context
    HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

    // Use TextOutA to draw the text
    TextOutA(hdc, clientRect.left + 10, clientRect.top + 10, textToDisplay, strlen(textToDisplay)); // Use TextOutA for ANSI character strings

    // Don't forget to select the old font back into the HDC when you're done
    SelectObject(hdc, hOldFont);

    // Release the custom font handle when you're finished
    DeleteObject(hFont);

    EndPaint(hWnd, &ps);
}
