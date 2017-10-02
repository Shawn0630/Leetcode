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

int twoSumClosest(vector<int>& nums, int start, int target) {
	int min = INT_MAX;
	int min_sum;
	int end = nums.size() - 1;	
	while(start < end) {
		int sum = nums[start] + nums[end];
		int diff = nums[start] + nums[end] + target;
		fou << nums[start] << " + " << nums[end] << " - " << target << " = " << diff << endl;
		if(abs(diff) < min) {
			min = abs(diff);
			min_sum = sum;
		}
		if(min == 0) return min_sum;
		else if(diff < 0) {
			start++;
		} else {
			end--;
		}
	}
	return min_sum;
}

int threeSumClosest(vector<int>& nums, int target) {
	int min = INT_MAX;
	int min_sum;
  	sort(nums.begin(), nums.end());
  	int size = nums.size();
    for(int i = 0; i < size - 3 + 1; i++) {
    	if(i > 0 && nums[i - 1] == nums[i]) continue;
    	fou << "select " << nums[i] << endl;
    	int value = twoSumClosest(nums, i + 1, nums[i] - target);
    	fou << "value " << value << endl;
    	int sum = value + nums[i];
    	fou << "sum = " << sum << endl;
    	int diff = abs(sum - target);
    	if(diff < min) {
    		min = diff;
    		min_sum = sum;
    	}
    }
    return min_sum;
}


int main() {
	string line;
	bool isFirstLine = true, isSecondLine = false, isInputFinished = false;
	vector<int> nums;
	int target;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		if(isFirstLine) {
			isFirstLine = false;
			isSecondLine = true;
			int num;
			while(iss >> num) {
				nums.push_back(num);
			}

		} else if(isSecondLine) {
			isFirstLine = true;
			isSecondLine = false;
			iss >> target;
			isInputFinished = true;
		} 
		if(isInputFinished) {
			isFirstLine = true;
			isInputFinished = false;
			cout << threeSumClosest(nums, target) << endl;
			nums.clear();
			target = 0;
		}
	}
}