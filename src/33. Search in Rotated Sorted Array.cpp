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

using namespace std;

// mid == 0 || nums[mid - 1] or 
// mid - 1 >= 0 && nums[mid - 1]

int findPivot(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (mid < right && nums[mid] > nums[mid + 1]) {
            return mid + 1;
        } else if (nums[mid - 1] > nums[mid] && mid > left) {
            return mid;
        } else {
            if (nums[mid] < nums[left]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    return 0;
}

int findTarget(vector<int> &nums, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int search(vector<int> &nums, int target) {
    if (nums.size() == 0) {
        return -1;
    }
    int pivot = findPivot(nums);
    int left = findTarget(nums, pivot, nums.size() - 1, target);
    int right = findTarget(nums, 0, pivot - 1, target);

    if (left == -1 && right == -1) {
        return -1;
    } else if (left == -1) {
        return right;
    } else {
        return left;
    }
}