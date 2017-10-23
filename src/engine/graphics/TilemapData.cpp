#include "TilemapData.h"

namespace engine { namespace graphics {
    TilemapData::TilemapData()
    {
        engine::console::Logger::getInstancePtr()->log("TilemapData initialized...\n");

        textureManagerPtr = TextureManager::getInstancePtr();
    }

    void TilemapData::setSize(int u, int v)
    {
        uSize = u;
        vSize = v;
        tileVector.resize(uSize * vSize);
    }
}}