#include "test4.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "4. Median of Two Sorted Arrays.cpp"
#include <iostream>
using namespace std;

Test4::Test4(){};

Test4::~Test4(){};

void Test4::SetUp(){};

void Test4::TearDown(){};

TEST_F(Test4, TEST4)
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int> v2;
    v2.push_back(4);

    vector<int> v3;
    v3.push_back(1);
    v3.push_back(3);

    vector<int> v4;
    v4.push_back(2);

    vector<int> v5;
    v5.push_back(2);
    vector<int> v6;
    v6.push_back(2);

    EXPECT_EQ((double)(2 + 3) / (double)2, findMedianSortedArrays(v1, v2));
    EXPECT_EQ((double)2, findMedianSortedArrays(v3, v4));
    EXPECT_EQ((double)(2 + 2) / (double)2, findMedianSortedArrays(v5, v6));
}