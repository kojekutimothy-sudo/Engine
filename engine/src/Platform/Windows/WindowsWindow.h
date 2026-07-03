#pragma once

#include <windows.h>
#include <string>

class WindowsWindow
{
public:
    WindowsWindow();

    bool Create(HINSTANCE hInstance, int nCmdShow, int width, int height, const std::string& title);
    void MessageLoop();

private:
    HWND m_Handle;

    static LRESULT CALLBACK WndProc(
        HWND hwnd,
        UINT msg,
        WPARAM wParam,
        LPARAM lParam
    );
};