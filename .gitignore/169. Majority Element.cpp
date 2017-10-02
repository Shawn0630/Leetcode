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
#include <cctype>
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int me = 0;
    for(int i = 0; i < nums.size(); i++) {
    	if(me == nums[i]) {
    		count++;
    	} else if(count == 0) {
    		me = nums[i];
    	} else {
    		count--;
    	}
    }

    count = 0;
    for(int i = 0; i < nums.size(); i++) {
    	if(me == nums[i]) {
    		count++;
    	}
    }

    if(count > nums.size() / 2) {
    	return me;
    } else {
    	return -1;
    }
}

int majorityElement_bit_manipulation(vector<int>& nums) {
    int bitcount[32];
    memset(bitcount, 0, sizeof(bitcount));
    int ans = 0;

    for(int i = 0; i < nums.size(); i++) {
    	for(int j = 0; j < 32; j++) {
    		if(nums[i] & (1 << j)) {
    			bitcount[j]++;
    		}
    	}
    }

    for(int i = 0; i < 32; i++) {
    	if(bitcount[i] > nums.size() / 2) {
    		ans |= (1 << i);
    	}
    }
    
    return ans;
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
		cout << "The majorityElement is " << majorityElement_bit_manipulation(v) << endl;
	}
}