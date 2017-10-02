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

int findDuplicate(vector<int>& nums) {
	int slow = 0;
	int fast = 0;
	do {
		slow = nums[slow];
		fast = nums[nums[fast]];
		fou << "slow " << slow << " fast " << fast << endl;
	} while(slow != fast);
	fast = 0;
	fou << "reset" << endl;
	while(slow != fast) {
		slow = nums[slow];
		fast = nums[fast];
		fou << "slow " << slow << " fast " << fast << endl;
	}
	return slow;        
}

int findDuplicate2(vector<int>& nums) {
	

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
		cout << findDuplicate(nums) << endl;
		cout << findDuplicate2(nums) << endl;
		cout << endl;
		nums.clear();
	}
}