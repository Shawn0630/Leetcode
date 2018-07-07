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

vector<int> findDuplicates(vector<int>& nums) {
	vector<int> res;
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] == i + 1) continue;
		while(nums[nums[i] - 1] != nums[i]) {
			int temp;
			temp = nums[nums[i] - 1];
			nums[nums[i] - 1] = nums[i];
			nums[i] = temp;
		}
	}
	/*for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;*/

	for(int i = 0; i < nums.size(); i++) {
		//cout << "nums[" << i << "] = " << nums[i] << " i + 1 = " << i + 1 << endl;
		if(nums[i] != i + 1) {
			//cout << "push " << nums[i] << endl;
			res.push_back(nums[i]);
		} 
	}

	return res;
	        
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
		vector<int> res = findDuplicates(nums);
		for(int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
		nums.clear();
	}
}