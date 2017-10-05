#include "test_ConsoleQueue.h"
#include <iostream>

namespace engine {
    void TestConsoleQueue::SetUp()
    {
        ;
    }

    TEST_F(TestConsoleQueue, CorrectlyAddsLines)
    {
        consoleQueue.addDebugLine(DebugLine("test string"));
        EXPECT_EQUAL(consoleQueue.getNumLines(), 1);
    }
}