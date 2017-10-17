include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/engine
	${PROJECT_SOURCE_DIR}/includes
	${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
	)

set(
    ANIMATION_SOURCES
	AnimationHandler.cpp
	AnimationController.cpp
	FrameData.cpp
	)

add_library(
    animation  
    ${ANIMATION_SOURCES}
    )

target_link_libraries(
    animation
    ${COMMON_LIBRARIES}
    )