add_subdirectory(engine)
add_subdirectory(common)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
    )

set(SOURCES 
    main.cpp
    engine/Application.cpp
    )

set(LIBRARIES
# engine
    animation
    graphics
    console
    input
    random
    states
    scene
    gameobject
    lua
    gui
# common
    math
    )

add_executable(main ${SOURCES})

target_link_libraries(
    main 
    ${COMMON_LIBRARIES} 
    ${LIBRARIES}
    )

target_compile_definitions(
    main PUBLIC
    -std=c++11
    -Wall
    )

