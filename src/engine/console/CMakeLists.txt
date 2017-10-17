include_directories(
    ${PROJECT_SOURCE_DIR}/src/engine
	${PROJECT_SOURCE_DIR}/includes
	${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
	)

set(CONSOLE_SOURCES
	DebugConsole.cpp
	ConsoleQueue.cpp
	DebugLine.cpp
	)

add_library(
	console
	${CONSOLE_SOURCES}
	)

target_link_libraries(
	console
	graphics
	animation
	${COMMON_LIBRARIES}
	)