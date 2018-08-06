#include "test81.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "81. Search in Rotated Sorted Array II.cpp"
#include <iostream>
using namespace std;

Test81::Test81(){};

Test81::~Test81(){};

void Test81::SetUp(){};

void Test81::TearDown(){};


TEST_F(Test81, TEST_FIND_TARGET)
{
    vector<int> empty_vector;
    EXPECT_EQ(-1, findTarget(empty_vector, 0, empty_vector.size() - 1, 1));

    vector<int> single_vector;
    single_vector.push_back(1);
    EXPECT_EQ(0, findTarget(single_vector, 0, single_vector.size() - 1, 1));

    int dual_vector_array[2] = {0, 0};
    vector<int> dual_vector(dual_vector_array, dual_vector_array + sizeof(dual_vector_array) / sizeof(dual_vector_array[0]));
    EXPECT_EQ(0, findTarget(dual_vector, 0, dual_vector.size() - 1, 0));

    int dual_vector_array_reverse[2] = {0, 1};
    vector<int> dual_vector_reverse(dual_vector_array_reverse, dual_vector_array_reverse + sizeof(dual_vector_array_reverse) / sizeof(dual_vector_array_reverse[0]));
    EXPECT_EQ(1, findTarget(dual_vector_reverse, 0, dual_vector_reverse.size() - 1, 1));

    int tri_array_with_duplication[3] = {0, 1, 1};
    vector<int> tri_vector_with_duplication(tri_array_with_duplication, tri_array_with_duplication + sizeof(tri_array_with_duplication) / sizeof(tri_array_with_duplication[0]));
    EXPECT_EQ(1, findTarget(tri_vector_with_duplication, 0, tri_vector_with_duplication.size() - 1, 1));

    int tri_array_with_duplication2[7] = {2, 5, 6, 0, 0, 1, 2};
    vector<int> tri_vector_with_duplication2(tri_array_with_duplication2, tri_array_with_duplication2 + sizeof(tri_array_with_duplication2) / sizeof(tri_array_with_duplication2[0]));
    EXPECT_EQ(3, findTarget(tri_vector_with_duplication2, 3, tri_vector_with_duplication2.size() - 1, 0));
}

TEST_F(Test81, TEST_SEARCH)
{
    int a1[7] = {2, 5, 6, 0, 0, 1, 2};
    vector<int> v1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    EXPECT_EQ(true, search(v1, 0));

    int a2[3] = {1, 3, 5};
    vector<int> v2(a2, a2 + sizeof(a2) / sizeof(a2[0]));
    EXPECT_EQ(true, search(v2, 1));
}
