#include "test220.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "220. Contains Duplicate III.cpp"
#include <iostream>
using namespace std;

Test220::Test220(){};

Test220::~Test220(){};

void Test220::SetUp(){};

void Test220::TearDown(){};

TEST_F(Test220, TEST_RESULT) {
    int a1[] = {1, 2, 3, 1};
    vector<int> v1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    EXPECT_EQ(true, containsNearbyAlmostDuplicate(v1, 3, 0));

    int a2[] = {1, 0, 1, 1};
    vector<int> v2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    EXPECT_EQ(true, containsNearbyAlmostDuplicate(v2, 1, 2));

    int a3[] = {1, 5, 9, 1, 5, 9};
    vector<int> v3(a3, a3 + sizeof(a3)/sizeof(a3[0]));
    EXPECT_EQ(false, containsNearbyAlmostDuplicate(v3, 2, 3));

    int a4[] = {-1, 2147483647};
    vector<int> v4(a4, a4 + sizeof(a4)/sizeof(a4[0]));
    EXPECT_EQ(false, containsNearbyAlmostDuplicate(v4, 1, 2147483647));
}