include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/engine
	${PROJECT_SOURCE_DIR}/includes
	${SFML_INCLUDE_DIR} 
    ${LUA_INCLUDE_DIR} 
	)

set(GRAPHICS_SOURCES
	Sprite.cpp
    Vector.cpp
    TextureManager.cpp
    Tilemap.cpp
    TilemapData.cpp
    BeamEffect.cpp
    ParticleArray.cpp
    )

add_library(
    graphics
    ${GRAPHICS_SOURCES}
    )

target_link_libraries(
# engine
    graphics 
    console
    animation 
    input
    random
# common
    math
    ${COMMON_LIBRARIES}
    )
