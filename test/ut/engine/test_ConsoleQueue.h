#pragma once

#include "gtest/gtest.h"
#include "ConsoleQueue.h"

namespace engine
{
    class TestConsoleQueue : public testing::Test 
    {
    protected:
        virtual void SetUp();

        ConsoleQueue consoleQueue;
    };
}