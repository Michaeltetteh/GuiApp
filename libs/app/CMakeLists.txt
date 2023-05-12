include(FetchContent)
FetchContent_Declare(glfw
    GIT_REPOSITORY "https://github.com/glfw/glfw"
    GIT_TAG "3.3.8"
    GIT_SHALLOW ON
)
FetchContent_Declare(glm
    GIT_REPOSITORY "https://github.com/Michaeltetteh/glm"
    GIT_TAG "0.9.9.8"
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(glfw glm)

add_subdirectory(glad)

include_directories(gui_app ${CMAKE_CURRENT_SOURCE_DIR}/libs/app/glad)
add_library(gui_app 
    STATIC
        application.hpp 
        application.cpp
)
target_link_libraries(gui_app glad glfw glm)
