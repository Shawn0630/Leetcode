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

TEST_F(Test215, TEST_PATTION)
{
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(1);
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

   cout << partition(v1, 0, v1.size() - 1) << endl;
   cout << partition(v2, 0, v2.size() - 1) << endl;
   cout << partition(v3, 0, v3.size() - 1) << endl;
   cout << partition(v4, 0, v4.size() - 1) << endl;
   cout << partition(v5, 0, v5.size() - 1) << endl;
}