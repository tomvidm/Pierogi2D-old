include_directories(
    ${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/includes
	${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
	)

set(CONSOLE_SOURCES
	DebugConsole.cpp
	ConsoleQueue.cpp
	DebugLine.cpp
	ValueField.cpp
	Logger.cpp
	)

add_library(
	console
	${CONSOLE_SOURCES}
	)

target_link_libraries(
	console
	graphics
	animation
	input
	${COMMON_LIBRARIES}
	)