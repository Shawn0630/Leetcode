#include "test33.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "33. Search in Rotated Sorted Array.cpp"
#include <iostream>
using namespace std;

Test33::Test33(){};

Test33::~Test33(){};

void Test33::SetUp(){};

void Test33::TearDown(){};

TEST_F(Test33, TEST_PIVOT)
{
    int a1[3] = {0, 1, 2};
    vector<int> v1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    EXPECT_EQ(0, findPivot(v1));

    int a4[3] = {1, 2, 0};
    vector<int> v4(a4, a4 + sizeof(a4) / sizeof(a4[0]));
    EXPECT_EQ(2, findPivot(v4));

    int a5[3] = {2, 0, 1};
    vector<int> v5(a5, a5 + sizeof(a5) / sizeof(a5[0]));
    EXPECT_EQ(1, findPivot(v5));

    int a2[7] = {2, 3, 4, 5, 6, 0, 1};
    vector<int> v2(a2, a2 + sizeof(a2) / sizeof(a2[0]));
    EXPECT_EQ(5, findPivot(v2));

    int a3[7] = {3, 4, 5, 6, 0, 1, 2};
    vector<int> v3(a3, a3 + sizeof(a3) / sizeof(a3[0]));
    EXPECT_EQ(4, findPivot(v3));

    int a6[1] = {0};
    vector<int> v6(a6, a6 + sizeof(a6) / sizeof(a6[0]));
    EXPECT_EQ(0, findPivot(v6));

    int a7[2] = {3, 1};
    vector<int> v7(a7, a7 + sizeof(a7) / sizeof(a7[0]));
    EXPECT_EQ(1, findPivot(v7));

    int a8[8] = {4, 5, 6, 7, 8, 1, 2, 3};
    vector<int> v8(a8, a8 + sizeof(a8) / sizeof(a8[0]));
    EXPECT_EQ(5, findPivot(v8));
}

TEST_F(Test33, TEST_BINARY_SEARCH)
{
    int a1[3] = {0, 1, 2};
    vector<int> v1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    EXPECT_EQ(0, findTarget(v1, 0, v1.size(), 0));

    int a4[3] = {0, 1, 2};
    vector<int> v4(a4, a4 + sizeof(a4) / sizeof(a4[0]));
    EXPECT_EQ(1, findTarget(v4, 0, v4.size(), 1));

    int a5[3] = {0, 1, 2};
    vector<int> v5(a5, a5 + sizeof(a5) / sizeof(a5[0]));
    EXPECT_EQ(2, findTarget(v5, 0, v5.size(), 2));

    int a6[3] = {0, 1, 2};
    vector<int> v6(a6, a6 + sizeof(a6) / sizeof(a6[0]));
    EXPECT_EQ(-1, findTarget(v6, 0, v6.size(), 3));

    int a7[1] = {0};
    vector<int> v7(a7, a7 + sizeof(a7) / sizeof(a7[0]));
    EXPECT_EQ(0, findTarget(v7, 0, v7.size(), 0));

    int a8[1] = {0};
    vector<int> v8(a8, a8 + sizeof(a8) / sizeof(a8[0]));
    EXPECT_EQ(-1, findTarget(v8, 0, v8.size(), 1));
}

TEST_F(Test33, TEST_SEARCH)
{
    int a1[3] = {0, 1, 2};
    vector<int> v1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    EXPECT_EQ(0, search(v1, 0));

    int a4[3] = {0, 1, 2};
    vector<int> v4(a4, a4 + sizeof(a4) / sizeof(a4[0]));
    EXPECT_EQ(1, search(v4, 1));

    int a5[3] = {0, 1, 2};
    vector<int> v5(a5, a5 + sizeof(a5) / sizeof(a5[0]));
    EXPECT_EQ(2, search(v5, 2));

    int a6[3] = {0, 1, 2};
    vector<int> v6(a6, a6 + sizeof(a6) / sizeof(a6[0]));
    EXPECT_EQ(-1, search(v6, 3));

     int a2[7] = {2, 3, 4, 5, 6, 0, 1};
    vector<int> v2(a2, a2 + sizeof(a2) / sizeof(a2[0]));
    EXPECT_EQ(2, search(v2, 4));

    int a3[7] = {3, 4, 5, 6, 0, 1, 2};
    vector<int> v3(a3, a3 + sizeof(a3) / sizeof(a3[0]));
    EXPECT_EQ(6, search(v3, 2));

    int a7[1] = {0};
    vector<int> v7(a7, a7 + sizeof(a7) / sizeof(a7[0]));
    EXPECT_EQ(0, search(v7, 0));

    int a8[8] = {4, 5, 6, 7, 8, 1, 2, 3};
    vector<int> v8(a8, a8 + sizeof(a8) / sizeof(a8[0]));
    EXPECT_EQ(4, search(v8, 8));
}