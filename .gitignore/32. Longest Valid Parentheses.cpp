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
#include <cctype>
#include <algorithm>

using namespace std;

ifstream fin("infile.txt");
ofstream fou("oufile.txt");

int longestValidParentheses(string s) {
	const int MAXN = 100000;
	int dp[MAXN];
	dp[0] = 0;
	for(int i = 1; i <= s.length(); i++) {
		if(s[i - 1] == '(') {
			dp[i] = 0;
		} else if(s[i - 1] == ')'){
			int j = i - 2 - dp[i - 1];
			if(j < 0 || s[j] == ')') dp[i] = 0;
			else dp[i] = dp[j] + 2 + dp[i - 1];
		}
	}
	int max = dp[1];
	for(int i = 1; i <= s.length(); i++) {
		if(max < dp[i]) max = dp[i];
		fou << "dp[" << i << "] = " << dp[i] << endl;
	}
	return max;
}

int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		cout << longestValidParentheses(line) << endl;
	}
}