#include "test219.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "219. Contains Duplicate II.cpp"
#include <iostream>
using namespace std;

Test219::Test219(){};

Test219::~Test219(){};

void Test219::SetUp(){};

void Test219::TearDown(){};

TEST_F(Test219, TEST_RESULT) {
    int a1[] = {1, 2, 3, 1};
    vector<int> v1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    EXPECT_EQ(true, containsNearbyDuplicate(v1, 3));

    int a2[] = {1, 0, 1, 1};
    vector<int> v2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    EXPECT_EQ(true, containsNearbyDuplicate(v2, 1));

    int a3[] = {1, 2, 3, 1, 2, 3};
    vector<int> v3(a3, a3 + sizeof(a3)/sizeof(a3[0]));
    EXPECT_EQ(false, containsNearbyDuplicate(v3, 2));
}