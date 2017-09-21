#include "test_Pool.h"

namespace engine
{
    void TestPool::SetUp()
    {
        ;
    }

    TEST_F(TestPool, ShouldCorrectlyInitialize)
    {
        EXPECT_EQ(pool.getPoolSize(), 16);
        EXPECT_EQ(pool.getNumObjects(), 0);
    }

    TEST_F(TestPool, ShouldCorrectlySetStates)
    {
        pool.setState(0, HAS_BEEN_USED);
        pool.addState(1, HAS_BEEN_USED | ACTIVE);
        pool.toggleState(2, HAS_BEEN_USED | ACTIVE);
        pool.subState(2, ACTIVE);

        EXPECT_EQ(pool.getState(0), HAS_BEEN_USED);
        EXPECT_EQ(pool.getState(1), HAS_BEEN_USED | ACTIVE);
        EXPECT_EQ(pool.getState(2), HAS_BEEN_USED);
    }

    TEST_F(TestPool, CorrectlyReturnsFreeSlots)
    {
        for (uint i = 0; i < 8; i++)
        {
            pool.activateObject();
        }  
        pool.deactivateObject(2);
        pool.deactivateObject(4);
        pool.deactivateObject(6);

        EXPECT_EQ(pool.getFirstAvailableIndex(), 2);
        EXPECT_EQ(pool.getFirstAvailableIndex(2), 4);
        EXPECT_EQ(pool.getFirstAvailableIndex(7), 8);

        pool.activateObject();

        EXPECT_EQ(pool.getFirstAvailableIndex(), 4);
    }
}