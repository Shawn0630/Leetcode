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

//[start, end);
void reverseString(string& s, int start, int end) {
	char temp;
	for(int i = 0; i < (end - start) / 2; i++) {
		temp = s[start + i];
		s[start + i] = s[end - i - 1];
		s[end - i - 1] = temp;
	}
}

string reverseStr(string s, int k) {
	int start = 0;
	string res = s;
	for(int i = 0; i * 2 * k < res.length(); i++) {
		start = i * 2 * k;
		if(start + k > res.length()) reverseString(res, start, res.length());
		else reverseString(res, start, start + k);
	}
	return res;
}



int main() {
   string line;
   while (getline(fin, line)) {
   	  if(line.size() == 0) break;
   	  int k;
   	  string s;
   	  istringstream iss(line);
   	  iss >> s >> k;
      cout << reverseStr(s, k) << endl;
   }
}
