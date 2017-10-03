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


int singleNumber(vector<int>& nums) {
  int ans = 0;
  for(int i = 0; i < 32; i++) {
  	int count = 0;
  	int bit = 1;
  	bit = bit << i;
  	fou << "bit " << bit << endl;
  	for(int j = 0; j < nums.size(); j++) {
  		if(nums[j] & bit) count++;// & is checking 1. 
  	} 
  	if(count % 3 != 0) {
  		ans |= bit;
  	}
  	fou << "ans " << ans << endl; 
  }
  return ans;
}

int singleNumber2(vector<int>& nums) {
	int one = 0, two = 0, three = 0;// mark "1" if each digit that appears "1" in once, twice and third time.
	for(int i = 0; i < nums.size(); i++) {
		two |= (one & nums[i]); // | is adding "1" to a specific digit & is computing carry
		one ^= nums[i]; // ^ is computing adding without carry
		three = ~(one & two);//& is computing the digit that appear "1" both in one and two
		one &= three;//& can also clear "1" and pick specific digit
		two &= three;//& can also clear "1" and pick specific digit
	}
	return one;
}


int main() {
	/*if(28 & 8) cout << "true" << endl;
	else cout << "false" << endl;
	cout << (28 & 8) << endl;*/
	string line;
	int num;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		vector<int> nums;
		while(iss >> num) {
			nums.push_back(num);
		}
		cout << singleNumber(nums) << endl;
	}
}
