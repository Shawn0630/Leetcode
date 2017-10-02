#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for(int i = 0; i < nums.size(); i++) {
    	result ^= nums[i];
    } 
    return result;
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");

	string line;
	vector<int> in;

	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		int num = 0;
		while(iss >> num) {
			in.push_back(num);
		}
		cout << "The single num is " << singleNumber(in) << endl;
	}
}