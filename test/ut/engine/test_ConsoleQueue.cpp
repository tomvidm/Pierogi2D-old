#include "test_ConsoleQueue.h"
#include <iostream>

namespace engine {
    void TestConsoleQueue::SetUp()
    {
        ;
    }

    TEST_F(TestConsoleQueue, CorrectlyAddsLines)
    {
        EXPECT_EQ(consoleQueue.getDebugString(), "");
        std::string testString = "test string";
        DebugLine debugLine(testString);
        for (int i = 0; i < 10; i++)
        {
            consoleQueue.addDebugLine(testString);
        }
        
        EXPECT_EQ(consoleQueue.getNumLines(), 10);
        consoleQueue.addDebugLine(testString);
        EXPECT_EQ(consoleQueue.getNumLines(), 10);

        EXPECT_EQ(consoleQueue.getDebugString(), "test string\ntest string\ntest string\ntest string\ntest string\ntest string\ntest string\ntest string\ntest string\ntest string\n");
    }
}