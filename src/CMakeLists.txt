#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions

set(SFML_ROOT "../SFML-2.4.2")

find_package(SFML 2 REQUIRED main network audio graphics window system)
find_package(Lua 5.2 REQUIRED)

add_subdirectory(engine)

include_directories("${PROJECT_BINARY_DIR}")
include_directories(${SFML_INCLUDE_DIR} ${LUA_INCLUDE_DIR} "../includes")
include_directories(
    engine
    engine/graphics
    )

set(SOURCES 
    main.cpp
    engine/Application.cpp
    engine/TextureHandler.cpp
    engine/AnimationHandler.cpp
    engine/graphics/Sprite.cpp
    engine/graphics/AnimationController.cpp
    engine/graphics/FrameData.cpp
    engine/graphics/VectorArray.cpp
    engine/graphics/Vector.cpp
    )

set(LIBRARIES
    ${LUA_LIBRARIES}
    ${SFML_LIBRARIES}
    ${SFML_DEPENDENCIES}
    )

add_executable(main ${SOURCES})


target_link_libraries(main ${LIBRARIES})
target_compile_definitions(main PUBLIC
                        -std=c++11
                        -Wall
                        )

