include_directories(
    ${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/includes
	${SFML_INCLUDE_DIR} 
	${LUA_INCLUDE_DIR}
	)

set(CONSOLE_SOURCES
	Interpolation.cpp
	)

add_library(
	math
	${CONSOLE_SOURCES}
	)

target_link_libraries(
	math
	${COMMON_LIBRARIES}
	)