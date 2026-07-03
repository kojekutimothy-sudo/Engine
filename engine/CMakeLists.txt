add_library(Engine STATIC
    src/Platform/Windows/WindowsWindow.cpp
)

target_include_directories(Engine PUBLIC
    ${CMAKE_SOURCE_DIR}/engine/include
)