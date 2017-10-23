#pragma once

#include "gtest/gtest.h"
#include "engine/console/ConsoleQueue.h"

namespace engine
{
    class TestConsoleQueue : public testing::Test 
    {
    protected:
        virtual void SetUp();

        console::ConsoleQueue consoleQueue;
    };
}