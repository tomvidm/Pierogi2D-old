#include "TilemapData.h"

namespace engine { namespace graphics {
    TilemapData::TilemapData()
    {
        engine::console::Logger::getInstancePtr()->log("TilemapData initialized...\n");
    }

    void TilemapData::setSize(int u, int v)
    {
        uSize = u;
        vSize = v;
        tileVector.reserve(uSize * vSize);
    }
}}