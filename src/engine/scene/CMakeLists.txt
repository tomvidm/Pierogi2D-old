include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
    )

set(SCENE_SOURCES
    Scene.cpp
    )

add_library(
    scene
    ${SCENE_SOURCES}
    )

target_link_libraries(
    scene
    gameobject
    lua
    ${COMMON_LIBRARIES}
    )