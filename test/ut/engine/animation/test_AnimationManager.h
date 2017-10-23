#pragma once

#include "gtest/gtest.h"
#include "engine/animation/AnimationManager.h"

namespace engine
{
    class TestAnimationHandler : public testing::Test 
    {
    protected:
        virtual void SetUp();

        animation::AnimationManager* animManagerPtr;
    };
}