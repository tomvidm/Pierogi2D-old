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
    )

set(COMMON_LIBRARIES
    ${LUA_LIBRARIES}
    ${SFML_LIBRARIES}
    ${SFML_DEPENDENCIES}
    )

set(LIBRARIES
    animation
    graphics
)

add_executable(main ${SOURCES})


target_link_libraries(main ${COMMON_LIBRARIES} ${LIBRARIES})
target_compile_definitions(main PUBLIC
                        -std=c++11
                        -Wall
                        )

