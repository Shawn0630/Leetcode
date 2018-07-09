#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cctype>
#include <algorithm>

using namespace std;

void swap(vector<int> &nums, int i, int j)
{
    int temp;
    temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    return;
}

void reverse(vector<int> &nums, int i, int j)
{
    while (i < j)
    {
        swap(nums, i, j);
        i++;
        j--;
    }
    return;
}

void nextPermutation(vector<int> &nums) {

    if (nums.size() < 2) return;

    int i = nums.size() - 2;
    while(i >= 0 && nums[i] >= nums[i + 1]) i--;
    if (i == -1) {
        reverse(nums, 0, nums.size() - 1);
        return;
    }
    int j = nums.size() - 1;
    while(j > 0 && nums[j] <= nums[i]) j--;
    swap(nums, i, j);
    reverse(nums, i + 1, nums.size() - 1);
    return;
}