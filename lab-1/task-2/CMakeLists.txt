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
        src/graphics/shapes/CircleShape.h
        src/graphics/shapes/CompositeShape.h
        src/graphics/house/Door.h
        src/graphics/shapes/IShape.h
        src/graphics/shapes/RectangleShape.h
        src/graphics/shapes/TriangleShape.h
        src/graphics/house/Wall.h
        src/graphics/house/SmallWindow.h
        src/graphics/house/BigWindow.h
        src/graphics/house/Roof.h
        src/graphics/house/Flue.h
        src/graphics/house/Slope.h
        src/graphics/house/House.h
        src/graphics/fence/Board.h
        src/graphics/fence/Fence.h
        src/graphics/Image.h
        src/graphics/background/Background.h
        src/graphics/background/Tree.h
        src/graphics/background/Cloud.h
)
target_link_libraries(main PRIVATE SFML::Graphics)
