#include "test_ConsoleQueue.h"
#include <iostream>

namespace engine {
    void TestConsoleQueue::SetUp()
    {
        ;
    }

    TEST_F(TestConsoleQueue, CorrectlyAddsLines)
    {
        std::string testString = "test string";
        DebugLine debugLine(testString);
        //consoleQueue.addDebugLine(testString);
        EXPECT_EQ(consoleQueue.getNumLines(), 1);
    }
}