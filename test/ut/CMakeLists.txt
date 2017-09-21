include_directories(${gtest_SOURCE_DIR}/include)
include_directories(../../src/engine)

add_subdirectory(engine)

set(TEST_SOURCES
    test_Trivial.cpp
    engine/test_Pool.cpp
    engine/test_Tree.cpp
    engine/test_SceneNodeManager.cpp
    )

add_executable(run_ut ${TEST_SOURCES})
target_link_libraries(run_ut gtest_main)