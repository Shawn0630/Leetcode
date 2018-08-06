#include "test.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "63. Unique Paths II.cpp"
#include <iostream>
using namespace std;

Test::Test(){};

Test::~Test(){};

void Test::SetUp(){};

void Test::TearDown(){};


TEST_F(Test, TEST_CASE_1) {
    int a1[] = {0, 0, 0};
    vector<int> v1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    int a2[] = {0, 1, 0};
    vector<int> v2(a2, a2 + sizeof(a2) / sizeof(a2[0]));
    int a3[] = {0, 0, 0};
    vector<int> v3(a3, a3 + sizeof(a3) / sizeof(a3[0]));

    vector<vector<int>> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    EXPECT_EQ(2, uniquePathsWithObstacles(v));
}

TEST_F(Test, TEST_CASE_2) {
    int a1[] = {1};
    vector<int> v1(a1, a1 + sizeof(a1) / sizeof(a1[0]));

    vector<vector<int>> v;
    v.push_back(v1);

    EXPECT_EQ(0, uniquePathsWithObstacles(v));
}

TEST_F(Test, TEST_CASE_3) {
    int a1[] = {1, 0};
    vector<int> v1(a1, a1 + sizeof(a1) / sizeof(a1[0]));

    vector<vector<int>> v;
    v.push_back(v1);

    EXPECT_EQ(0, uniquePathsWithObstacles(v));
}