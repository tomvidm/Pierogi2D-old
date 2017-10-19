include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/engine
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
    )

set(GAMEOBJECT_SOURCES
    Entity.cpp
    )

add_library(
    gameobject
    ${GAMEOBJECT_SOURCES}
    )

target_link_libraries(
    gameobject 
    ${COMMON_LIBRARIES}
    )