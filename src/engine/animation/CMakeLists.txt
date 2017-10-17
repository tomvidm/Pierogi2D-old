include_directories(
    ${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/includes
	${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
	)

set(
    ANIMATION_SOURCES
	engine/animation/AnimationHandler.cpp
	engine/animation/AnimationController.cpp
	engine/animation/FrameData.cpp
	)

add_library(
    animation  
    ${ANIMATION_SOURCES}
    )

target_link_libraries(
    animation
    ${COMMON_LIBRARIES}
    )