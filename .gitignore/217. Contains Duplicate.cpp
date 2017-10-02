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


bool containsDuplicate(vector<int>& nums) {
     //unordered_map<int, int> m;
	 map<int, int> m;
     //unordered_map<int, int>::iterator it;
     map<int, int>::iterator it;
     for(int i = 0; i < nums.size(); i++) {
     	it = m.find(nums[i]);
     	if(it != m.end()) {
     		m[nums[i]]++;
     		return true;
     	}
     	m[nums[i]] = 0;
     }
     return false;
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;
	while (getline(fin, line)) {
		vector<int> in;
		if(line.size() == 0) break;
		istringstream iss(line);
		int num;
		while(iss >> num) {
			in.push_back(num);
		}
		cout << containsDuplicate(in) << endl;
	}
}