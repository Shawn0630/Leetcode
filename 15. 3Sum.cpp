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

void twoSum(vector<vector<int> >& res, vector<int> nums, int start, vector<int> chosen, int target) {
	int end = nums.size() - 1;
	while(start < end) {
		int sum = nums[start] + nums[end];
		if(sum == target) {
			chosen.push_back(nums[start]);
			chosen.push_back(nums[end]);
			res.push_back(chosen);
			chosen.pop_back();
			chosen.pop_back();
			start++;
			end--;
			while(start < nums.size() && nums[start - 1] == nums[start]) start++;
			while(end >= 0 && nums[end] == nums[end + 1]) end--;
		} else if(sum < target)start++;
		else end--; 
	}
	return;
}

void threeSumDFS(vector<vector<int> >& res, vector<int> nums, vector<int> chosen) {
	int size = nums.size();
	for(int i = 0; i < size; i++) {
		if(i > 0 && nums[i] == nums[i - 1]) continue;
		chosen.push_back(nums[i]);
		twoSum(res, nums, i + 1, chosen, -nums[i]);
		chosen.pop_back();
	}
	return;
}


vector<vector<int>> threeSum(vector<int>& nums) {
     vector<vector<int> > res;
     vector<int> chosen;
     sort(nums.begin(), nums.end());
     threeSumDFS(res, nums, chosen);
     return res;
}

int main() {
	string line;
	vector<int> nums;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		int num;
		while(iss >> num) {
			nums.push_back(num);
		}
		vector<vector<int>> res = threeSum(nums);
		for(int i = 0; i < res.size(); i++) {
			for(int j = 0; j < res[i].size(); j++) {
				cout << res[i].at(j) << " ";
			}
			cout << endl;
		}
		nums.clear();
	}
}