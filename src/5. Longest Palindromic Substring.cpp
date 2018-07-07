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

 string longestPalindrome(string s) {

 	bool** isPalidrome = new bool*[s.size()];
 	for(int i = 0; i < s.size(); i++) {
 		isPalidrome[i] = new bool[s.size()];
 	}
 	int max = 1;
 	int max_start = 0;
 	int max_end = 0;

 	for(int i = 0; i < s.size(); i++) {
 		for(int j = i; j < s.size(); j++) {
 			if(i == j) isPalidrome[i][j] = true;
 			else isPalidrome[i][j] = false;
 		}
 	}

 	for(int end = 0; end < s.size(); end++) {
 		for(int start = 0; start < end; start++) {
 			if(s[start] == s[end] && (end - start < 2 || isPalidrome[start + 1][end - 1])) isPalidrome[start][end] = true;
 			if(isPalidrome[start][end] && (end - start + 1 > max)) {
 				max = end - start + 1;
 				max_start = start;
 				max_end = end;
 			}
 		}
 	}

 	return s.substr(max_start, max_end - max_start + 1);
        
 }


int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		cout << longestPalindrome(line) << endl;
	}
}