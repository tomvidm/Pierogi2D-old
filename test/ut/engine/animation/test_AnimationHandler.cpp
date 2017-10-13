#include "test_AnimationHandler.h"
#include <iostream>

namespace engine
{
    void TestAnimationHandler::SetUp()
    {
        ;
    }

    TEST_F(TestAnimationHandler, CorrectlyImportsAnimationFromLuaTable)
    {
        animationHandler.loadFromLuaTable("../../../resources/images/spritesheet_testsprite.lua", "spritesheet_testsprite");
        //FrameData animationHandler.get("spritesheet_testsprite");
        EXPECT_TRUE(false);
    }
}