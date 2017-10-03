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


int lengthOfLongestSubstring(string s) {
   int* lengthOfLongestSubstringEndingInI = new int[s.length()];
   lengthOfLongestSubstringEndingInI[0] = 1;
   for(int i = 1; i < s.length(); i++) {
   	if(s[i] == s[i - 1]) {
   		lengthOfLongestSubstringEndingInI[i] = 1;
   	} else {

   		int a = lengthOfLongestSubstringEndingInI[i - 1] + 1;
   		int b = lengthOfLongestSubstringEndingInI[i - 1 - lengthOfLongestSubstringEndingInI[i - 1]];
   		if(a < b) {
   			lengthOfLongestSubstringEndingInI[i] = b;
   		} else {
   			lengthOfLongestSubstringEndingInI[i] = a;
   		}
   	}
   }
   int max = lengthOfLongestSubstringEndingInI[0];
   for(int i = 1; i < s.length(); i++) {
   	if(lengthOfLongestSubstringEndingInI[i] > max) {
   		max = lengthOfLongestSubstringEndingInI[i];
   	}
   }
   return max;
}

int main() {
	string line;
	vector<int> nums;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		cout << lengthOfLongestSubstring(line) << endl;

	}
}