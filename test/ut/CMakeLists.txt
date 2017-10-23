add_subdirectory(engine)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/engine
	${PROJECT_SOURCE_DIR}/src/engine/animation
	${PROJECT_SOURCE_DIR}/src/engine/graphics
    ${PROJECT_SOURCE_DIR}/src/engine/console
    ${PROJECT_SOURCE_DIR}/src/engine/input
	${PROJECT_SOURCE_DIR}/includes
	${SFML_INCLUDE_DIR}
	${LUA_INCLUDE_DIR}
# googletest
	${gtest_SOURCE_DIR}/include
	)

set(TEST_SOURCES
    test_Trivial.cpp
    engine/test_Pool.cpp
    engine/test_ConsoleQueue.cpp
    engine/test_ValueField.cpp
    engine/test_DebugLine.cpp
    engine/animation/test_AnimationManager.cpp
    )

set(LIBRARIES
	gtest_main
	animation
    graphics
    console
    input
    )

add_executable(
    run_ut 
    ${TEST_SOURCES}
    )

target_link_libraries(
    run_ut 
    ${LIBRARIES}
    ${COMMON_LIBRARIES}
    )


