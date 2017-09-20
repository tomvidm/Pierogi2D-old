include_directories(${gtest_SOURCE_DIR}/include)
include_directories(../../src/engine)

set(TEST_SOURCES
    test_Trivial.cpp
    )

add_executable(run_ut ${TEST_SOURCES})
target_link_libraries(run_ut gtest_main)