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
    l++;
    while(l <= r) {
       while(pivot < nums[r] && l <= r) r--;
       while(nums[l] < pivot && l <= r) l++;
       if (nums[l] > nums[r]) {
           swap(nums, l, r);
       }
    }
    if(nums[r] < pivot) {
        swap(nums, r, pivot_pos);
    }

    return r;
}

int findKthLargest(vector<int> &nums, int k) {


}