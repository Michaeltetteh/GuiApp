#pragma once

#include "glad/glad.h"
#include "../imgui/imgui.h"
#include "../imgui/backends/imgui_impl_glfw.h"
#include "../imgui/backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string>


namespace gui {

    static void glfw_error_callback(int error, const char* description);

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
    void key_callback(GLFWwindow* window, int key, int scancode, int actions, int mods);

    class Application
    {
    public:
        Application(const char* title, int width, int height);
        ~Application();

        decltype(auto)  get_window() { return m_window; }

        void            run();
        virtual void    update() = 0;

    private:
        void            initialize();
        bool            init_glfw();
        void            config_imgui();
        void            poll_event();
        void            start_frame();
        void            render();

        GLFWwindow*     m_window;
        std::string     m_title;
        int             m_width;
        int             m_height;

        const char*     m_glsl_version;
        ImVec4          m_clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    };


}
