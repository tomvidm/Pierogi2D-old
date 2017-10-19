cmake_minimum_required(VERSION 3.0)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

project(SFML-Game-Engine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (NOT ${gtest_SOURCE_DIR})
# ====================================================================
# ====================================================================
# Copypasta from: https://crasci    t.com/2015/07/25/cmake-gtest/
# ====================================================================
# ====================================================================
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build")

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()
endif()

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate
# ====================================================================
# ====================================================================
# Copypasta end
# ====================================================================
# ====================================================================

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions

# IN FindSFML, the variable SFML_ROOT is a search directory for
# the find package operation.
set(SFML_ROOT "SFML-2.4.2")

# Find packages
find_package(SFML 2 REQUIRED main network audio graphics window system)
find_package(Lua 5.2 REQUIRED)

set(COMMON_LIBRARIES
    ${LUA_LIBRARIES}
    ${SFML_LIBRARIES}
    ${SFML_DEPENDENCIES}
    )

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)