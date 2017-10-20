include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
    )

set(INPUT_SOURCES
    Window.cpp
    Widget.cpp
    )

add_library(
    gui
    ${INPUT_SOURCES}
    )

target_link_libraries(
    gui
    ${COMMON_LIBRARIES}
    )