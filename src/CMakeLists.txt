#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
set(SFML_ROOT "../SFML-2.4.2")
find_package(SFML 2 REQUIRED main network audio graphics window system)

add_subdirectory(engine)

include_directories("${PROJECT_BINARY_DIR}")
include_directories(
    engine
    engine/graphics
    )

set(SOURCES 
    main.cpp
    engine/Application.cpp
    engine/TextureHandler.cpp
    engine/graphics/AnimatedSprite.cpp
    engine/graphics/SpriteAnimation.cpp
    )

add_executable(main ${SOURCES})

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(main ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

