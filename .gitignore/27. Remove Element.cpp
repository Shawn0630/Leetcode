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

int removeDuplicates(vector<int>& nums) {
   int i = 0; 
   int j = 0;
   while(j < nums.size()) {
   	   while(j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
   	   nums[i++] = nums[j++];
   }
   return i;
}


int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		vector<int> nums;
		int num;
		while(iss >> num) {
			nums.push_back(num);
		}
		cout << removeDuplicates(nums) << endl;
	}
}