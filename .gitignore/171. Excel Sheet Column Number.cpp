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

int titleToNumber(string s) {
	int num = 0;
	for(int i = 0; i < s.size(); i++) {
		num = num * 26 + (s[i] - 'A' + 1);
	}
	return num;
        
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;

	while (getline(fin, line)) {
		if(line.size() == 0) break;
		cout << "The string is " << line << endl;
		cout << "Title is " << titleToNumber(line) << endl;
	}	
}