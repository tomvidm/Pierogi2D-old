#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
set(SFML_ROOT "SFML-2.4.2")
find_package(SFML 2 REQUIRED network audio graphics window system)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(main main.cpp)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(main ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()