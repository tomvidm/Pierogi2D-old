include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
    )

set(CONSOLE_SOURCES
    GameState.cpp
    GameStateStack.cpp
    GameStateTest.cpp
    )

add_library(
    states
    ${CONSOLE_SOURCES}
    )

target_link_libraries(
    states
    scene
    input
    ${COMMON_LIBRARIES}
    )