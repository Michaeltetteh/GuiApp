#pragma once
#include "application.hpp"

static bool show_dock = true;

class Docking : public gui::Application
{
public:
    Docking(const char* title, int width, int height);
    ~Docking() = default;

    void update() override;

private:
    static void show_docking_disabled_message()
    {
        ImGuiIO& io = ImGui::GetIO();
        ImGui::Text("ERROR: Docking is not enabled! See Demo > Configuration.");
        ImGui::Text("Set io.ConfigFlags |= ImGuiConfigFlags_DockingEnable in your code, or ");
        ImGui::SameLine(0.0f, 0.0f);
        if (ImGui::SmallButton("click here"))
            io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    }

    void show_example_app_dock_space(bool *p_open);
};