cmake_minimum_required(VERSION 3.20)

project(mysfml)

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
)

FetchContent_MakeAvailable(SFML)

add_executable(sfml_window src/code.cpp)

target_link_libraries(sfml_window
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)
