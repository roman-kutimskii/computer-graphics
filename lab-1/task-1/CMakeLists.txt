cmake_minimum_required(VERSION 3.30)
project(task_1)

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

add_executable(main src/main.cpp
        src/ILetter.h
        src/LetterP.h
        src/LetterB.h
        src/LetterK.h
)
target_link_libraries(main PRIVATE SFML::Graphics)
