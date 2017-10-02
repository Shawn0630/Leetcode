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

vector<int> subvector(vector<int> v, int begin, int end) {
	vector<int> r;
	for(int i = 0; i < v.size(); i++) {
		if(i >= begin && i < end) {
			r.push_back(v[i]);
		}
	}
	/*fou << "return vector" << endl;
	for(int i = 0; i < r.size(); i++) {
		fou << r[i] << " ";
	}
	fou << endl;*/
	return r;
}

void twoSum(vector<vector<int> >& res, vector<int> left, int start, vector<int> chosen, int terms, int target) {
	int end = left.size() - 1;
	while(start < end) {
		int sum = left[start] + left[end];
		if(target == sum){
			chosen.push_back(left[start]);
			chosen.push_back(left[end]);
			res.push_back(chosen);
			chosen.pop_back();
			chosen.pop_back();
			start++;
			end--;
			while(start < left.size() && left[start - 1] == left[start]) start++;
			while(end > 0 && left[end] == left[end + 1]) end--;
		} else {
			if(sum < target) start++;
			else end--;
		}
	}
	return;
}

void fourSumDFS(vector<vector<int> >& res, /*map<vector<int>, bool>& m, */vector<int> left, int start, vector<int> chosen, int terms, int target) {
	/*fou << "search " << endl;
	fou << "left" << endl;
	for(int i = 0; i < left.size(); i++) {
		fou << left[i] << " ";
	}
	fou << endl;
	fou << "chosen" << endl;
	for(int i = 0; i < chosen.size(); i++) {
		fou << chosen[i] << " ";
	}
	fou << endl;
	fou << "term = " << terms << " target = " << target << endl;
	fou << endl;*/
	if(terms == 1) {
		for(int i = start; i < left.size(); i++) {
			if(left[i] == target) {
				chosen.push_back(left[i]);
				/*
				sort(chosen.begin(), chosen.end());
				if(m.find(chosen) == m.end()) {
					m[chosen] = true;
					res.push_back(chosen);
				}*/
				res.push_back(chosen);
				return;
			}
		}
		return;
	}
	else if(terms == 2) {
		twoSum(res, left, start, chosen, terms, target);
		return;
	}
	for(int i = start; i < (int)left.size() - terms + 1; i++) {
		if(i > start && left[i] == left[i - 1]) continue;
		
		//vector<int> a = subvector(left, 0, i);
		//vector<int> b = subvector(left, i + 1, left.size());
		//vector<int> v;
		//v.insert(v.end(), a.begin(), a.end());
		//v.insert(v.end(), b.begin(), b.end());
		
		/*fou << "a vector" << endl;
		for(int j = 0; j < a.size(); j++) {
			fou << a[j] << " ";
		}
		fou << endl;
		fou << "b vector" << endl;
		for(int j = 0; j < b.size(); j++) {
			fou << b[j] << " ";
		}
		fou << endl;*/
		
		/*
		!!!!!IMPORTANT!!!!!NEVER CHANGE THE PARAMETER LIKE THIS
		chosen.push_back(left[i]);
		*/

		/*
		Solution One
		vector<int> c(chosen);
		c.push_back(left[i]);*/

		//Solution Two
		chosen.push_back(left[i]);
		fourSumDFS(res, /*m, */left, i + 1, chosen, terms - 1, target - left[i]);
		chosen.pop_back();
	}
}

vector<vector<int> > fourSum(vector<int>& nums, int target) {
      vector<vector<int> > res;
      if(nums.empty()) return res;
      vector<int> chosen;
      //map<vector<int>, bool> m;
      sort(nums.begin(), nums.end());
      fourSumDFS(res/*, m*/, nums, 0, chosen, 4, target);
      return res;
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
		/*	cout << "nums is " << endl;
			for(int i = 0; i < nums.size(); i++) {
				cout << nums[i] << " ";
			}
			cout << endl;
			cout << "target is " << target << endl;*/
			
			vector<vector<int>> res = fourSum(nums, target);
			for(int i = 0; i < res.size(); i++) {
				for(int j = 0; j < res[i].size(); j++) {
					cout << res[i].at(j) << " ";
				}
				cout << endl;
			}

			nums.clear();
			target = 0;
		}
	}
}