cmake_minimum_required(VERSION 3.22)

project(GuiApp)

set(CMAKE_CXX_STANDARD 17)


set(BACKENDS_HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/backends/imgui_impl_glfw.h
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/backends/imgui_impl_opengl3.h)

set(BACKENDS_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/backends/imgui_impl_glfw.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/backends/imgui_impl_opengl3.cpp)


set(HEADERS_CXX_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/imgui.h
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/imconfig.h
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/imgui_internal.h
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/imstb_rectpack.h
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/imstb_textedit.h
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/imstb_truetype.h
)

set(SOURCES_CXX_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/imgui_widgets.cpp
)

add_subdirectory(libs)


include_directories(GuiApp
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/app
)

add_executable(GuiApp 
    ${BACKENDS_HEADERS} 
    ${BACKENDS_SRC} 
    ${HEADERS_CXX_FILES} 
    ${SOURCES_CXX_FILES}
    src/docking.hpp
    src/docking.cpp
    src/main.cpp
)
target_link_libraries(GuiApp gui_app)