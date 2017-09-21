#pragma once

#include "gtest/gtest.h"
#include "Pool.h"

namespace engine
{
    class TestPool : public testing::Test 
    {
    protected:
        virtual void SetUp();

        Pool<int, 16> pool;
    };
}