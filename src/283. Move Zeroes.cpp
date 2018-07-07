#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

void printVector(vector<int> nums) {
	for(int i = 0; i < nums.size(); i++) {
			cout << nums[i] << " ";
	}
	cout << endl;
}

void swap(vector<int>& nums, int non_zero_index, int zero_index) {
	int temp;
	temp = nums[non_zero_index];
	nums[non_zero_index] = nums[zero_index];
	nums[zero_index] = temp;
}

void moveZeroes(vector<int>& nums) {
	int non_zero_index = 0;
	int zero_index = 0;
	while(non_zero_index < nums.size() && zero_index < nums.size()) {
		while(nums[zero_index] != 0 && zero_index < nums.size()) zero_index++;
		non_zero_index = zero_index + 1;
		while(nums[non_zero_index] == 0 && non_zero_index < nums.size()) non_zero_index++;
		if(non_zero_index < nums.size() && zero_index < nums.size() && nums[non_zero_index] != 0 && nums[zero_index] == 0) {
//			cout << "swap " << non_zero_index << " to " << zero_index << endl;
			swap(nums, non_zero_index, zero_index);
//			printVector(nums);
		}
	}
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");


	string line;
	vector<int> nums;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		int num;
		while(iss >> num) {
			nums.push_back(num);
		}
		cout << "Input: ";
		printVector(nums);
		moveZeroes(nums);
		cout << "Output: ";
		printVector(nums);
		nums.clear();
	}
}

