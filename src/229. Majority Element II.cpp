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

vector<int> majorityElement(vector<int>& nums) {
	int count_a = 0, count_b = 0;
	int a = 0, b = 0;
	vector<int> res;
	for(int i = 0; i < nums.size(); i++) {
		if(a == nums[i]) {
			count_a++;
		} else if(b == nums[i]) {
			count_b++;
		} else if(count_a == 0) {
			a = nums[i];
			count_a++;
		} else if(count_b == 0) {
			b = nums[i];
			count_b++;
		} else {
			count_a--;
			count_b--;
		}
	}

	count_a = 0;
	count_b = 0;
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] == a) {
			count_a++;
		} else if(nums[i] == b) {
			count_b++;
		}
	}

	if(count_a > nums.size() / 3) {
		res.push_back(a);
	}
	if(count_b > nums.size() / 3) {
		res.push_back(b);
	}
	return res;  
}

void printVector(vector<int> v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		int num;
		vector<int> v;
		istringstream iss(line);
		while(iss >> num) {
			v.push_back(num);
		}
		printVector(v);
		cout << "The majorityElement is ";
		printVector(majorityElement(v));
	}
}