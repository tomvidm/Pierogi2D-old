include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
    )

set(INPUT_SOURCES
    InputTextField.cpp
    Mouse.cpp
    )

add_library(
    input
    ${INPUT_SOURCES}
    )

target_link_libraries(
    input
    ${COMMON_LIBRARIES}
    )