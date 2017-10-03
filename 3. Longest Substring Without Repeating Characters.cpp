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


int lengthOfLongestSubstring(string str) {
   unordered_map<char, int> s;
   unordered_map<char, int>::iterator it;
   if(str.length() == 0) return 0;
   int max = 1;
   int start = 0;
   int end = 1;
   while(end <= str.length()) {
      if (s.find(str[end - 1]) == s.end()) {
         s[str[end - 1]] = end - 1;
      } else {
         for(int i = start; i < end - 1; i++) {
            cout << str[i];
         }
         cout << endl;
         if(end - 1 - start > max) {
            max = end - start - 1;
         } 
         if(start < s[str[end - 1]] + 1) start = s[str[end - 1]] + 1;
         s[str[end - 1]] = end - 1;
      }
      end++;
   }
   for(int i = start; i < end - 1; i++) {
      cout << str[i];
   }
   cout << endl;
   if(end - 1 - start > max) max = end - 1 - start;
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