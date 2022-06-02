#pragma once

#ifndef GUIAPP_GUIAPP_HPP
#define GUIAPP_GUIAPP_HPP

#include <GLFW/glfw3.h>
#include "../libs/dear/imgui.h"
#include "../libs/dear/backends/imgui_impl_glfw.h"
#include "../libs/dear/backends/imgui_impl_opengl3.h"


class GuiApp
{
public:
    GuiApp();

    void init(const char*);
    void update();
    void render();
    void shutdown();

    GLFWwindow *getWindow() { return window;}
    ImVec4 getClearColor() { return clear_color;}
    bool get_demo_window() { return show_demo_window;}
    bool get_another_window(){return show_another_window;}

private:
    GLFWwindow *window;
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    bool window_created = true;
    ImGuiIO io;
};

#endif