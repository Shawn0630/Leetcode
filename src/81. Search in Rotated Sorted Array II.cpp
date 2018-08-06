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

// while(left <= right) left = 0, right = nums.size() - 1
int findTarget(vector<int>& nums, int left, int right, int target) {

    int left_edge = left;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target && (mid == left_edge || nums[mid - 1] < nums[mid])) {
            return mid;
        } else {
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    return -1;
}

// left target mid right
bool search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return true;
        }
        else if (nums[left] == nums[mid]) left++;
        else if (nums[mid] > nums[left]) {
            if (nums[left] <= target && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }

    return false;
}