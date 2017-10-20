#include "gtest/gtest.h"

#include "ValueField.h"

typedef unsigned int uint;

TEST(ValueFieldTest, IntValue)
{
    engine::console::ValueField intValue((int)(-5));
    EXPECT_EQ("-5", intValue.get());
}

TEST(ValueFieldTest, UintValue)
{
    engine::console::ValueField uintValue((uint)5);
    EXPECT_EQ("5", uintValue.get());
}

TEST(ValueFieldTest, FloatValue)
{
    engine::console::ValueField floatValue((float)5.f);
    EXPECT_EQ("5.000000", floatValue.get());
}

TEST(ValueFieldTest, StringValue)
{
    engine::console::ValueField stringValue("hello world");
    EXPECT_EQ("hello world", stringValue.get());
}

TEST(ValueFieldTest, IntPtrValue)
{
    int i = 1;
    engine::console::ValueField intPtrValue(&i);
    EXPECT_EQ("1", intPtrValue.get());
    i = 5;
    EXPECT_EQ("5", intPtrValue.get());
}