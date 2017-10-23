include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/engine
	${PROJECT_SOURCE_DIR}/includes
	${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
	)

set(GRAPHICS_SOURCES
	Sprite.cpp
	VectorArray.cpp
    Vector.cpp
    TextureHandler.cpp
    TextureManager.cpp
    Tilemap.cpp
    TilemapData.cpp
    )

add_library(
    graphics
    ${GRAPHICS_SOURCES}
    )

target_link_libraries(
    graphics 
    console
    animation 
    input
    random
    ${COMMON_LIBRARIES}
    )
