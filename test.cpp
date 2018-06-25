#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <optional>

using namespace std;

template <typename T>
void mergeVectors(vector<T> &nums1, vector<T> &nums2) {
    T j = 0;
    typename vector<T>::iterator it1 = nums1.begin();
    while (it1 != nums1.end() && j < nums2.size()) {
        if (*it1 > nums2[j])
        {
            it1 = nums1.insert(it1, nums2[j]);
            j++;
        }
        else
        {
            it1++;
        }
    }

    while (j < nums2.size()) {
        it1 = nums1.insert(it1, nums2[j]);
        it1++;
        j++;
    }
}

template<typename T>
void swap(T* a, T* b) {
    if (*a == *b) return;

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

template <typename T>
int kth(vector<T>& nums1, vector<T>& nums2, int k) {
    mergeVectors(nums1, nums2);
    return nums1[k - 1];
}

int main() {
    int arr1[5] = {2, 3, 6, 7, 9};
    int arr2[4] = {1, 4, 8, 10};
    vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    cout << kth(nums1, nums2, 5) << endl;

    char c = 'a';
    char d = 'd';
    swap(&c, &d);
    cout << c << d << endl;

    int a = 3;
    int b = 4;
    swap(&a, &b);
    cout << a << b << endl;
    return 0;
}
