#include "test.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "62. Unique Paths.cpp"
#include <iostream>
using namespace std;

Test::Test(){};

Test::~Test(){};

void Test::SetUp(){};

void Test::TearDown(){};


TEST_F(Test, TEST_CASE_1) {
   
    EXPECT_EQ(3, uniquePaths(3, 2));
}

TEST_F(Test, TEST_CASE_2) {
    EXPECT_EQ(28, uniquePaths(7, 3));
}
