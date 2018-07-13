#include "test31.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "31. Next Permutation.cpp"
#include <iostream>
using namespace std;

Test31::Test31(){};

Test31::~Test31(){};

void Test31::SetUp(){};

void Test31::TearDown(){};

TEST_F(Test31, TEST31)
{
    vector<int> test1;
    test1.push_back(1);
    test1.push_back(1);
    test1.push_back(5);
    nextPermutation(test1);

    vector<int> test2;
    test2.push_back(1);
    test2.push_back(2);
    nextPermutation(test2);

    vector<int> test3;
    test3.push_back(1);
    nextPermutation(test3);

    vector<int> test4;
    test4.push_back(1);
    test4.push_back(3);
    test4.push_back(2);
    nextPermutation(test4);

    EXPECT_THAT(test1, ::testing::ElementsAre(1, 5, 1));
    EXPECT_THAT(test2, ::testing::ElementsAre(2, 1));
    EXPECT_THAT(test3, ::testing::ElementsAre(1));
    EXPECT_THAT(test4, ::testing::ElementsAre(2, 1, 3));
}