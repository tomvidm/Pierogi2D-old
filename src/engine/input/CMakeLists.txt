include_directories(
    ${PROJECT_SOURCE_DIR}/src/engine
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
    )

set(CONSOLE_SOURCES
    InputTextField.cpp
    )

add_library(
    input
    ${CONSOLE_SOURCES}
    )

target_link_libraries(
    input
    ${COMMON_LIBRARIES}
    )