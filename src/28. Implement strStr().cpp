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

vector<int> preprocessing(string needle) {
	int j = 0;
	vector<int> P(needle.length() + 1, 0);//P[i] = max{a|B[0 ... a - 1] == B[i - a ... i - 1]}// j = P[i - 1] | 0 
	P[0] = 0;// P[i] is the length of the ongest prefix and suffix string of the string ending at i - 1;
	for(int i = 1; i < needle.length(); i++) {
		while(j > 0 && needle[j] != needle[i]){
			/*cout << "needle[" << j << "] = " << needle[j] << " needle[" << i << "] = " << needle[i] << endl;
			cout << "P[" << j << "] = " << P[j] << " P[" << i << "] = " << P[i] << " j = " << j << endl;*/
			j = P[j];	
		} 
		if(needle[j] == needle[i]) j++;
		P[i + 1] = j;
		for(int i  = 0; i < P.size(); i++){
    		cout << P[i] << " ";
    	}
    	cout << endl;
	}
	return P;
}

/*vector<int> getFail(string pattern) {
    int m = pattern.size();
    vector<int> fail(m+1, 0);
    for(int t=1; t<m; t++) {
        int p=fail[t];
        while(p && pattern[p] != pattern[t]) p = fail[p];
        fail[t+1] = (pattern[p] == pattern[t]) ? p+1 : 0;
    }
    return fail;
} */

// first occurance of needle in haystack
int strStr(string haystack, string needle) {
	if(needle.length() == 0)return 0;
	if(haystack.length() == 0) return -1;
    vector<int> P = preprocessing(needle);
    int j = 0;
    for(int i = 0; i < haystack.length(); i++) {
    	while(j > 0 && haystack[i] != needle[j]) j = P[j];
    	if(haystack[i] == needle[j]) j++;
    	if(j == needle.length()) return i- needle.length() + 1;
    }
    return -1;
}


int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		string haystack, needle;
		iss >> haystack;
		iss >> needle;
		cout << "haystack = " << haystack << " needle = " << needle << endl;
		cout << strStr(haystack, needle) << endl;
	}
}