include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
    )

set(CONSOLE_SOURCES
    LuaHelpers.cpp
    )

add_library(
    lua
    ${CONSOLE_SOURCES}
    )

target_link_libraries(
    lua
    ${COMMON_LIBRARIES}
    )