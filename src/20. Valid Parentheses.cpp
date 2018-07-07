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

bool isValid(string s) {
	stack<char> parentheses;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
			parentheses.push(s[i]);
		} else if(s[i] == ')') {
			if(!parentheses.empty() && parentheses.top() == '(') {
				parentheses.pop();
			} else return false;
		} else if(s[i] == '}') {
			if(!parentheses.empty() && parentheses.top() == '{') {
				parentheses.pop();
			} else return false;
		} else if(s[i] == ']') {
			if(!parentheses.empty() && parentheses.top() == '[') {
				parentheses.pop();
			} else return false;
		}
	}
	if(!parentheses.empty()) return false;
	else return true;
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		cout << "line " << line << endl;
		cout << isValid(line) << endl;
	}
}