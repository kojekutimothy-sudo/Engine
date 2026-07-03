#include <windows.h>
#include "../../engine/src/Platform/Windows/WindowsWindow.h"

int main()
{
    WindowsWindow window;

    if (!window.Create(GetModuleHandle(nullptr), 1, 800, 600, "Engine Window"))
        return -1;

    window.MessageLoop();
    return 0;
}