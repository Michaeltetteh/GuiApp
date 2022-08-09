#include "../headers/GuiApp.hpp"
#include "../headers/docking.hpp"


int main(int, char**)
{
    GuiApplication::setup();

    auto *App = new GuiApplication::GuiApp();

    App->init();
    int counter = 0;
    
    static bool show_dock = true;
    //main loop
    while(!glfwWindowShouldClose(App->getWindow()))
    {
        glfwPollEvents();

        App->begin();

        GuiApplication::ShowExampleAppDockSpace(&show_dock);
        
        ImGui::Begin("demo");
        bool buttonClicked = ImGui::Button("CLickMe",{60.0f,30.0f});
        if(buttonClicked)
            ++counter;
        ImGui::Text("Button Click Counter : %d",counter);
        ImGui::End();

        App->end();
    }
    // Cleanup
    App->shutdown();
}
