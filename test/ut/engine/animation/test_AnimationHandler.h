#pragma once

#include "gtest/gtest.h"
#include "AnimationHandler.h"

namespace engine
{
    class TestAnimationHandler : public testing::Test 
    {
    protected:
        virtual void SetUp();

        animation::AnimationHandler animationHandler;
    };
}