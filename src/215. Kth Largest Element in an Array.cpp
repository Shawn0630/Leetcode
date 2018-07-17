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

void swap(vector<int>& nums, int l, int r) {
    int temp = nums[l];
    nums[l] = nums[r];
    nums[r] = temp;
}

int partition(vector<int> & nums, int l, int r) {
    int pivot = nums[l];
    int pivot_pos = l;
    while(l <= r) {
        while (nums[l] >= pivot && l <= r)
            l++;
        while (pivot >= nums[r] && l <= r)
            r--;
        if (l < r) {
            swap(nums, l, r);
        }
    }
    swap(nums, r, pivot_pos);
    return r;
}

int findKthLargestUntil(vector<int> &nums, int left, int right, int k) {
    int pos = partition(nums, left, right);
    if (pos == k - 1) {
        return nums[pos];
    } else if (pos < k - 1){
        return findKthLargestUntil(nums, pos + 1, right, k);
    } else {
        return findKthLargestUntil(nums, left, pos - 1, k);
    }
}

int findKthLargest(vector<int> &nums, int k) {
    return findKthLargestUntil(nums, 0, nums.size() - 1, k);
}