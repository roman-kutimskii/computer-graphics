cmake_minimum_required(VERSION 3.30)
project(task_2)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY git@github.com:SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_MakeAvailable(SFML)

add_executable(
        main
        src/main.cpp
        src/graphics/CircleShape.h
        src/graphics/CompositeShape.h
        src/graphics/Door.h
        src/graphics/IShape.h
        src/graphics/RectangleShape.h
        src/graphics/TriangleShape.h
        src/graphics/Wall.h
        src/graphics/SmallWindow.h
        src/graphics/BigWindow.h
)
target_link_libraries(main PRIVATE SFML::Graphics)
