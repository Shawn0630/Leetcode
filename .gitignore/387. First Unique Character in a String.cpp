#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

int firstUniqChar(string s) {
	map<char, int> myMap;
	for(int i = 0; i < s.size(); i++) {
		myMap[s[i]]++;
	}
	int i;
	for(i = 0; i < s.size(); i++) {
		if(myMap[s[i]] == 1) {
			return i;
		}
	}
	if(i == s.size()) return -1;
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		cout << "Input " << line << endl;
		cout << "Output " << firstUniqChar(line) << endl;
	} 
}