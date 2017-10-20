#include "gtest/gtest.h"

#include "DebugLine.h"

typedef unsigned int uint;

TEST(DebugLineTest, Composition)
{
    engine::console::DebugLine debugLine;
    debugLine.addField(engine::console::ValueField(5));
    debugLine.addField(engine::console::ValueField(" apples on a tree"));
    debugLine.addField(engine::console::ValueField(" can only mean trouble."));
    EXPECT_EQ("5 apples on a tree can only mean trouble.", debugLine.get());
}