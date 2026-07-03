#include "WindowsWindow.h"

WindowsWindow::WindowsWindow()
    : m_Handle(nullptr)
{
}

bool WindowsWindow::Create(HINSTANCE hInstance, int nCmdShow, int width, int height, const std::string& title)
{
    const char CLASS_NAME[] = "WindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

    RegisterClass(&wc);

    m_Handle = CreateWindowEx(
        0,
        CLASS_NAME,
        title.c_str(),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        width,
        height,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    if (!m_Handle)
        return false;

    ShowWindow(m_Handle, nCmdShow);

    return true;
}

void WindowsWindow::MessageLoop() {
    MSG msg = {};

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT CALLBACK WindowsWindow::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        const char* text = "Hello World!";
        TextOutA(hdc, 50, 50, text, sizeof("Hello World!") - 1);

        EndPaint(hwnd, &ps);
        return 0;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

