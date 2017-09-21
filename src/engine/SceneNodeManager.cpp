#include "SceneNodeManager.h"

namespace engine
{
    void SceneNodeManager::updateAllNodes()
    {
        // Make a stack
        // Iterate over all objects:
        // * ignore inactive objects
        // * push "root" nodes to stack
        // * process each node
        // ** nodes with children calls updateNode(i)
        return;
    }

    bool SceneNodeManager::verifyOrdering() const
    {
        for (uint i = 0; i < sceneNodePool_.getPoolSize(); i++)
        {
            childNodes = sceneNodeTree_.childrenOf(i);
            if (!childNodes.empty())
            {
                for (uint c = 0; c < childNodes.size(); c++)
                {
                    if (i > c)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
}