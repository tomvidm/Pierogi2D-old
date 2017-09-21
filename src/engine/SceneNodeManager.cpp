#include "SceneNodeManager.h"

namespace engine
{
    uint SceneNodeManager::activateSceneNode()
    {
        return sceneNodePool_.activateObject();
    }

    uint SceneNodeManager::activateSceneNodeAfter(uint min_id)
    {
        return sceneNodePool_.activateObject();
    }

    void SceneNodeManager::updateAllNodes()
    {
        for (uint i = 0; i < sceneNodePool_.getFirstFreeIndex(); i++)
        {
            updateNode(i);
        }
    }

    void SceneNodeManager::updateNode()
    {
        return;
    }
}