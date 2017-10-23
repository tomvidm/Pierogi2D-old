#include "test_AnimationManager.h"

namespace engine
{
    void TestAnimationHandler::SetUp()
    {
        animManagerPtr = animation::AnimationManager::getInstancePtr();
    }

    TEST_F(TestAnimationHandler, CorrectlyImportsAnimationFromLuaTable)
    {
        animManagerPtr->loadFromFile("testsprite");
        animation::FrameData frameData = animManagerPtr->get("testsprite_walk_right");
        EXPECT_EQ(frameData.getNumFrames(), 8);
    }
}