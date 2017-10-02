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

/*bool repeatedSubstringPattern(string s) {
	vector<int> P(s.length() + 1, 0);
	P[0] = 0;
	int j = 0;
	for(int i = 1; i < s.length(); i++) {
		while(j > 0 && s[j] != s[i]) j = P[j];
		if(s[j] == s[i])j++;
		P[i + 1] = j;
	}
	for(int i = 0; i < P.size(); i++) {
		cout << P[i] << " ";
	}
	cout << endl;
	return true;
        
}*/

bool repeatedSubstringPattern(string str) {
        int i = 1, j = 0, n = str.size();
        vector<int> dp(n + 1, 0);
        while (i < n) {
            if (str[i] == str[j]) dp[++i] = ++j;
            else if (j == 0) ++i;
            else j = dp[j];
        }
        for(int i = 0; i < dp.size(); i++) {
        	cout << dp[i] << " ";
        }
        cout << endl;
        return dp[n] && (dp[n] % (n - dp[n]) == 0);
    }

int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		cout << repeatedSubstringPattern(line) << endl;
	}
}