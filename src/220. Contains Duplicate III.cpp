#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cctype>
#include <algorithm>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {

    if (k <= 0 || t < 0) return false;
    map<long long, long long> keytoValue;
    long long divider = t + 1;
    for (int i = 0; i < nums.size(); i++) {
        long long key = (long long)nums[i] / divider;
        if (nums[i] < 0) {
            key--;
        }
        if (keytoValue.find(key) != keytoValue.end() ||
            keytoValue.find(key + 1) != keytoValue.end() && keytoValue[key + 1] - nums[i] <= t ||
            keytoValue.find(key - 1) != keytoValue.end() && nums[i] - keytoValue[key - 1] <= t) {
                return true;
            }
        keytoValue[key] = nums[i];
        if (i >= k) {
            keytoValue.erase(nums[i - k] / divider);
        }
    }

    return false;
}