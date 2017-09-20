#pragma once

#include <stack>

#include "Pool.h"
#include "Tree.h"
#include "SceneNode.h"

#define MAX_NODES 64

namespace engine
{
    typedef unsigned int uint;
    typedef Pool<SceneNode, MAX_OBJECTS> SceneNodePool;

    /*
        For data coherence, updating each node by iterating through the array
        is desirable. If a node has a set of children, we want to update these children by updating the parent first,
        and maybe ignore the children until the parent is found.
    */
    enum class UpdateMode
    {
        IGNORE_SUBTREE,
        UPDATE_SUBTREE,
        UPDATE_SUBTREE_IF_ROOT
    };

    class ObjectManager
    {
    public:
        void updateAllNodes();
        void updateNode(uint id)
    private:
        utils::Tree<uint> sceneNodeTree_;
        SceneNodePool sceneNodePool_;
    };
}