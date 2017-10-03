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


vector<int> singleNumber(vector<int>& nums) {
	set<int> res;
	set<int>::iterator it;
 	for(int i = 0; i < nums.size(); i++) {
 		it = res.find(nums[i]);
 		if(it != res.end()) {
 			res.erase(it);
 		} else {
 			res.insert(nums[i]);
 		}
 		/*it = res.begin();
 		while(it != res.end()) {
 			cout << *it << " ";
 			it++;
 		}
 		cout << endl;*/
 	}
 	vector<int> ou(res.begin(), res.end());
 	//cout << "size = " << ou.size() << endl;
 	return ou;
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
		vector<int> res;
		while(iss >> num) {
			nums.push_back(num);
		}
		res = singleNumber(nums);
		for(int i = 0; i < nums.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
}
