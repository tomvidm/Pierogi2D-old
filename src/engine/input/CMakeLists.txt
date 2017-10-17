include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
    )

set(CONSOLE_SOURCES
    engine/input/InputTextField.cpp
    )

add_library(
    input
    ${CONSOLE_SOURCES}
    )

target_link_libraries(
    input
    ${COMMON_LIBRARIES}
    )