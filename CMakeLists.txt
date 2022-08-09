cmake_minimum_required(VERSION 3.2)
project(GuiApp)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -Wpedantic")

set(BACKENDS_HEADERS "libs/dear/backends/")
set(BACKENDS_SRC libs/dear/backends/imgui_impl_glfw.cpp libs/dear/backends/imgui_impl_opengl3.cpp)

set(IMGUI_HEADERS libs/dear/imgui.h libs/dear/imconfig.h libs/dear/imgui_internal.h
                  libs/dear/imstb_rectpack.h libs/dear/imstb_textedit.h
                  libs/dear/imstb_truetype.h)

set(IMGUI_SRC libs/dear/imgui.cpp libs/dear/imgui_draw.cpp
            libs/dear/imgui_tables.cpp libs/dear/imgui_widgets.cpp)

set(GUIAPP_HEADER headers/GuiApp.hpp)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(guiApp
        ${BACKENDS_HEADERS}
        ${BACKENDS_SRC}
        ${IMGUI_HEADERS}
        ${IMGUI_SRC}
        ${GUIAPP_HEADER} src/main.cpp )

target_link_libraries(guiApp ${CONAN_LIBS})