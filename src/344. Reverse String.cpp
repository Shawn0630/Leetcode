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


string reverseString(string s) {
	char temp;
	for(int i = 0; i < s.length() / 2; i++) {
		temp = s[i];
		s[i] = s[s.length() - i - 1];
		s[s.length() - i - 1] = temp;
	}
	return s;
}


int main() {
   string line;
   while (getline(fin, line)) {
      if(line.size() == 0) break;
      cout << reverseString(line) << endl;
   }
}
