include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/includes
    ${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
    )

set(RANDOM_SOURCES
    Random.cpp
    )

add_library(
    random
    ${RANDOM_SOURCES}
    )

target_link_libraries(
    random
    ${COMMON_LIBRARIES}
    )