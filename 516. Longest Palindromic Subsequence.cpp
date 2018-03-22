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


int longestPalindromeSubseq(string s) {
	int** longestPalidrome = new int*[s.length()];
	for(int i = 0; i < s.length(); i++) {
		longestPalidrome[i] = new int[s.length()];
	}

	
 }

int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		cout << longestPalindromeSubseq(line) << endl;
	}
}
