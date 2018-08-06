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

bool containsNearbyDuplicate(vector<int>& nums, int k) {

    set<int> s;

    for (int i = 0; i < nums.size(); i++) {

        if (s.find(nums[i]) != s.end()) {
            return true;
        }
        s.insert(nums[i]);
        if(i >= k) {
            s.erase(nums[i - k]);
        }
    } 

    return false;       
}