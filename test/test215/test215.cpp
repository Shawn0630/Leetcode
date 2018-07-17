#include "test215.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "215. Kth Largest Element in an Array.cpp"
#include <iostream>
using namespace std;

Test215::Test215(){};

Test215::~Test215(){};

void Test215::SetUp(){};

void Test215::TearDown(){};

TEST_F(Test215, TEST_PATITION_SINGLE_ELEMENT) {
    vector<int> single;
    single.push_back(2);

    EXPECT_EQ(0, partition(single, 0, single.size() - 1));
    EXPECT_THAT(single, ::testing::ElementsAre(2));
}

TEST_F(Test215, TEST_PARTITION_ELEMENTS) {
    vector<int> twoElement;
    twoElement.push_back(0);
    twoElement.push_back(1);

    EXPECT_EQ(1, partition(twoElement, 0, twoElement.size() - 1));
    EXPECT_THAT(twoElement, ::testing::ElementsAre(1, 0));
}

TEST_F(Test215, TEST_PARTITION_ELEMENTS_REVERSE)
{
    vector<int> twoElement;
    twoElement.push_back(1);
    twoElement.push_back(0);

    EXPECT_EQ(0, partition(twoElement, 0, twoElement.size() - 1));
    EXPECT_THAT(twoElement, ::testing::ElementsAre(1, 0));
}

TEST_F(Test215, TEST_KTH_ELEMENT) {
    vector<int> single;
    single.push_back(2);

    EXPECT_EQ(2, findKthLargest(single, 1));
}

TEST_F(Test215, TEST_KTH_ELEMENT_ELEMENTS) {
    vector<int> twoElement;
    twoElement.push_back(1);
    twoElement.push_back(2);

    EXPECT_EQ(1, findKthLargest(twoElement, 2));
}

TEST_F(Test215, TEST_KTH_ELEMENT_ELEMENTS_REVERSE)
{
    vector<int> twoElement;
    twoElement.push_back(2);
    twoElement.push_back(1);

    EXPECT_EQ(2, findKthLargest(twoElement, 1));
    EXPECT_EQ(1, findKthLargest(twoElement, 2));
}

TEST_F(Test215, TEST_KTH_ELEMENT_GENERAL)
{
    vector<int> general;
    general.push_back(3);
    general.push_back(2);
    general.push_back(1);
    general.push_back(5);
    general.push_back(6);
    general.push_back(4);

    EXPECT_EQ(5, findKthLargest(general, 2));
}

TEST_F(Test215, TEST_KTH_ELEMENT_GENERAL_WITH_DUPLICATION)
{
    vector<int> general;
    general.push_back(3);
    general.push_back(2);
    general.push_back(3);
    general.push_back(1);
    general.push_back(2);
    general.push_back(4);
    general.push_back(5);
    general.push_back(5);
    general.push_back(6);

    EXPECT_EQ(4, findKthLargest(general, 4));
}