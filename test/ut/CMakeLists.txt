include_directories(${PROJECT_SOURCE_DIR}/src/engine
					${PROJECT_SOURCE_DIR}/src/engine/animation
					${PROJECT_SOURCE_DIR}/src/engine/graphics
					${PROJECT_SOURCE_DIR}/includes
					${SFML_INCLUDE_DIR}
					${LUA_INCLUDE_DIR}
				# googletest
					${gtest_SOURCE_DIR}/include
					)

add_subdirectory(engine)

set(TEST_SOURCES
    test_Trivial.cpp
    engine/test_Pool.cpp
    engine/animation/test_AnimationHandler.cpp
    )

set(LIBRARIES
	gtest_main
	animation
    ${LUA_LIBRARIES}
    ${SFML_LIBRARIES}
    ${SFML_DEPENDENCIES}
    )

add_executable(run_ut ${TEST_SOURCES})
target_link_libraries(run_ut ${LIBRARIES})

