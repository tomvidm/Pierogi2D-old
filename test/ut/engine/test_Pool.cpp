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

    TEST_F(TestPool, ShouldCorrectlySetStates)
    {
        pool.setState(0, HAS_BEEN_USED);
        pool.addState(1, HAS_BEEN_USED | ACTIVE);
        pool.toggleState(2, HAS_BEEN_USED | ACTIVE);
        pool.subState(2, ACTIVE);

        ASSERT_EQ(pool.getState(0), HAS_BEEN_USED);
        ASSERT_EQ(pool.getState(1), HAS_BEEN_USED | ACTIVE);
        ASSERT_EQ(pool.getState(2), HAS_BEEN_USED);
    }
}