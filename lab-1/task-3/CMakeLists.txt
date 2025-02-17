cmake_minimum_required(VERSION 3.30)
project(task_3)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY git@github.com:glfw/glfw.git
        GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

set(GLAD_SOURCE_DIR ${CMAKE_SOURCE_DIR}/thirdparty/glad)
add_library(glad STATIC ${GLAD_SOURCE_DIR}/src/gl.c)
target_include_directories(glad PUBLIC ${GLAD_SOURCE_DIR}/include)

add_executable(main src/main.cpp
        src/Shader.h)
target_link_libraries(main glfw glad)
target_include_directories(main PRIVATE ${GLAD_SOURCE_DIR}/include ${glm_SOURCE_DIR})
