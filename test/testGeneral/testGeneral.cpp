#include "testGeneral.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "general.cpp"
#include <iostream>
using namespace std;

TestGeneral::TestGeneral(){};

TestGeneral::~TestGeneral(){};

void TestGeneral::SetUp(){};

void TestGeneral::TearDown(){};

TEST_F(TestGeneral, TEST_FIND_NUMBER)
{
   
    vector<int> case1;
    case1.push_back(1);
    case1.push_back(2);
    case1.push_back(3);

    EXPECT_EQ("YES", findNumber(case1, 1));
    EXPECT_EQ("NO", findNumber(case1, 4));
}

TEST_F(TestGeneral, TEST_ODD_NUMBERS) {
     EXPECT_THAT(oddNumbers(3, 9), ::testing::ElementsAre(3, 5, 7, 9));
}

TEST_F(TestGeneral, TEST_BRACES) {
    vector<string> case1;
    case1.push_back("{}[]()");
    case1.push_back("{[}]}");

    EXPECT_THAT(braces(case1), ::testing::ElementsAre("YES", "NO"));
}

TEST_F(TestGeneral, TEST_MOVES) {
    // vector<int> case1;
    // case1.push_back(13);
    // case1.push_back(10);
    // case1.push_back(21);
    // case1.push_back(20);

    // EXPECT_EQ(1, moves(case1));


    vector<int> case2;
    case2.push_back(8);
    case2.push_back(5);
    case2.push_back(11);
    case2.push_back(4);
    case2.push_back(6);

    EXPECT_EQ(2, moves(case2));

    // vector<int> case3;
    // case3.push_back(24);
    // case3.push_back(24);
    // case3.push_back(23);
    // case3.push_back(23);

    // EXPECT_EQ(0, moves(case3));
}