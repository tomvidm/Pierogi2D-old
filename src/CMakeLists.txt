add_subdirectory(engine)

include_directories(${PROJECT_SOURCE_DIR}/src/engine
                    ${PROJECT_SOURCE_DIR}/src/engine/animation
                    ${PROJECT_SOURCE_DIR}/src/engine/graphics
                    ${PROJECT_SOURCE_DIR}/includes
                    ${SFML_INCLUDE_DIR} 
                    ${LUA_INCLUDE_DIR} 
                    )

set(SOURCES 
    main.cpp
    engine/Application.cpp
# animations
    engine/animation/AnimationHandler.cpp
    engine/animation/AnimationController.cpp
    engine/animation/FrameData.cpp
# graphics
    engine/graphics/VectorArray.cpp
    engine/graphics/Vector.cpp
    engine/graphics/Sprite.cpp
    engine/graphics/TextureHandler.cpp
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

