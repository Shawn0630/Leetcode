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


/*
precedure:
1. The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
2. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
3. The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

requirement:
1. If the first sequence of non-whitespace characters in str is not a valid integral number, 
   or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 ->
   If no valid conversion could be performed, a zero value is returned.
2. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned. 


*/

int myAtoi(string str) {
	int64_t res = 0;
	int i = 0;
	bool isNegative = false;
	while(str[i] == ' ' && i < str.length()) i++;
	if(i == str.length()) return 0;
	if(str[i] == '-') {
		isNegative = true;
		i++;
	} else if(str[i] == '+') {
		isNegative = false;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9') {
		res = res * 10 + str[i] - '0';
		i++;
		if ((int64_t)((int32_t)res) != res) {
			if(isNegative) return INT_MIN;
			else return INT_MAX;
		}
	}
	if(isNegative) res = -res;
	return res;
}


int main() {
   cout << (int)0x7FFFFFFF << ", " << (int)0x80000000 << endl; 
   string line;
   while (getline(fin, line)) {
      if(line.size() == 0) break;
      cout << myAtoi(line) << endl;
   }
}
