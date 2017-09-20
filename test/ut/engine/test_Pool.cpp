#include "test_Pool.h"

namespace engine
{
    void TestPool::SetUp()
    {
        ;
    }

    TEST_F(TestPool, ShouldCorrectlyInitialize)
    {
        ASSERT_EQ(pool.getPoolSize(), 8);
        ASSERT_EQ(pool.getNumObjects(), 0);
    }
}