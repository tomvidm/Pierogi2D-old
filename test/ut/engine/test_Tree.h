#pragma once

#include "gtest/gtest.h"
#include "Tree.h"

namespace engine {
namespace utils {
    class TestTree : public testing::Test 
    {
    protected:
        virtual void SetUp();

        Tree<int> tree;
    };
}} // engine::utils
