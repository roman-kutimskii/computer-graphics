cmake_minimum_required(VERSION 3.30)
project(task_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(main src/main.cpp)
target_link_libraries(main
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET main POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:main>/plugins/platforms/")
        add_custom_command(TARGET main POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:main>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET main POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:main>")
    endforeach (QT_LIB)
endif ()

if (WIN32)
    set(PLUGIN_DIR "${QT_INSTALL_PATH}/plugins/imageformats")
    set(DEST_DIR "$<TARGET_FILE_DIR:main>/plugins/imageformats")

    add_custom_command(TARGET main POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory "${DEST_DIR}")

    file(GLOB PLUGIN_FILES "${PLUGIN_DIR}/*.dll")
    foreach (PLUGIN ${PLUGIN_FILES})
        add_custom_command(TARGET main POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy "${PLUGIN}" "${DEST_DIR}")
    endforeach ()
endif ()
