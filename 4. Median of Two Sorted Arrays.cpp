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
#include <queue>
#include <cctype>
#include <algorithm>

using namespace std;

ifstream fin("infile.txt");
ofstream fou("oufile.txt");

template <typename T>
void printVector(vector<T> &v) {
    bool first = true;
    for (int i = 0; i < v.size(); i++) {
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << v[i];
    }
    cout << endl;
}

template <typename T>
void printVector(vector<T> &v, int start, int end) {
    if (start >= v.size())
        return;
    bool first = true;
    for (int i = start; i < v.size() && i < end; i++) {
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << v[i];
    }
    cout << endl;
}

template <typename T>
void swap(vector<T>& nums, int a, int b) {
    T temp;
    temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

template <typename T>
void swap(T nums[], int a, int b) {
    T temp;
    temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void mergeVectors(vector<int> &nums1, vector<int> &nums2) {

    int j = 0;
    vector<int>::iterator it1 = nums1.begin();
    while (it1 != nums1.end() && j < nums2.size()) {
        if (*it1 > nums2[j]) {
            it1 = nums1.insert(it1, nums2[j]);
            j++;
        } else {
            it1++;
        }
    }

    while (j < nums2.size()) {
        it1 = nums1.insert(it1, nums2[j]);
        it1++;
        j++;
    }
}
// [start, end]
// notice k start at 1 while index start at 0 k == index + 1
int findKthLargestNum(vector<int> nums, int start, int end, int k) {
    int pivot = start;
    int left = start;
    int right = end;
    while (left <= right) {
        while (left <= right && nums[left] <= nums[pivot])
            left++;
        while (left <= right && nums[right] >= nums[pivot])
            right--;
        // right <= end - 1
        if (left < right) {
            cout << "swap nums[" << left << "] = " << nums[left] << " nums[" << right << "] = " << nums[right] << endl;
            swap(nums, left, right);
            printVector(nums);
        }
    }
    cout << "swap nums[" << pivot << "](pivot) = " << nums[pivot] << " nums[" << right << "] = " << nums[right] << endl;
    swap(nums, pivot, right);
    printVector(nums);
    // left of pivot <= pivot right of pivot >= pivot

    if (k == right + 1) {
        return nums[right];
    } else if (k > right + 1) {
        findKthLargestNum(nums, right + 1, end, k);
    } else if (k < right + 1) {
        findKthLargestNum(nums, start, right - 1, k);
    }
}

int findKthLargestNum(vector<int> nums, int k) {
    if (k < 0 || k > nums.size()) return -1;
    return findKthLargestNum(nums, 0, nums.size() - 1, k);
}

//[start end)  empty start >= end
//[start, end] empty start > end
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    
    // Solution 1:
    // mergeVectors(nums1, nums2);
    // printVector(nums1);
    // if (nums1.size() % 2 == 0) {
    //     return (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / (double)2;
    // } else {
    //     return nums1[nums1.size() / 2];
    // }

    // Solution 2:
    findKthLargestNum(nums1, 3); 

}

int main() {
    string line;
    int read = 0;
    vector<int> nums1, nums2;
    while (getline(fin, line)) {
        if (line.size() == 0) break;
        istringstream iss(line);
        int num;
         
        switch(read) {
            case 0:
                while (iss >> num) {
                    nums1.push_back(num);
                }
                read = 1;
                break;
            case 1:
                while (iss >> num) {
                    nums2.push_back(num);
                }
                printVector(nums1);
                printVector(nums2);
                swap(nums1, 1, 2);
                printVector(nums1);
                cout << findMedianSortedArrays(nums1, nums2) << endl;
                nums1.clear();
                nums2.clear();
                read = 0;
                break;
        }
    }
    return 0;
}