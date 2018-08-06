#include "test.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "61. Rotate List.cpp"
#include <iostream>
using namespace std;

Test::Test(){};

Test::~Test(){};

void Test::SetUp(){};

void Test::TearDown(){};


TEST_F(Test, TEST_CASE_1) {
   
    ListNode* node0= new ListNode(0);
    EXPECT_EQ(1, sizeOfList(node0));
}

TEST_F(Test, TEST_CASE_2) {
    ListNode* node0= new ListNode(0);
    ListNode* node1= new ListNode(1);
    node0->next = node1;

    EXPECT_EQ(2, sizeOfList(node0));
}

TEST_F(Test, TEST_CASE_3) {
    ListNode* node0= new ListNode(0);
    ListNode* node1= new ListNode(1);
    ListNode* node2= new ListNode(2);
    node0->next = node1;
    node1->next = node2;

    EXPECT_EQ(3, sizeOfList(node0));
}

TEST_F(Test, TEST_CASE_4) {
    ListNode* node0= new ListNode(0);
    ListNode* node1= new ListNode(1);
    ListNode* node2= new ListNode(2);
    node0->next = node1;
    node1->next = node2;

    EXPECT_EQ(0, lastOfList(node0, 2)->val);
}

TEST_F(Test, TEST_CASE_5) {
    ListNode* node0= new ListNode(0);
    ListNode* node1= new ListNode(1);
    ListNode* node2= new ListNode(2);
    node0->next = node1;
    node1->next = node2;

    EXPECT_EQ(1, lastOfList(node0, 1)->val);
}

TEST_F(Test, TEST_CASE_6) {
    ListNode* node0= new ListNode(0);
    ListNode* node1= new ListNode(1);
    ListNode* node2= new ListNode(2);
    node0->next = node1;
    node1->next = node2;

    EXPECT_EQ(2, lastOfList(node0, 0)->val);
}

TEST_F(Test, TEST_CASE_7) {
    ListNode* node0= new ListNode(0);
    ListNode* node1= new ListNode(1);
    ListNode* node2= new ListNode(2);
    node0->next = node1;
    node1->next = node2;

    EXPECT_EQ(NULL, lastOfList(node0, 3));
}

