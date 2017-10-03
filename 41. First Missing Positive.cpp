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
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cctype>
#include <algorithm>

using namespace std;

ifstream fin("infile.txt");
ofstream fou("oufile.txt");

int firstMissingPositive(vector<int>& nums) {
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] == i + 1) continue;
		while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
			int temp;
			temp = nums[nums[i] - 1];
			nums[nums[i] - 1] = nums[i];
			nums[i] = temp;
		}
	}
/*	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;*/

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] != i + 1) {
			return i + 1;
		} 
	}
	return nums.size() + 1;
}

int main() {
	string line;
	int num;
	vector<int> nums;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		while(iss >> num) {
			nums.push_back(num);
		}
		cout << firstMissingPositive(nums) << endl;
		nums.clear();
	}
}