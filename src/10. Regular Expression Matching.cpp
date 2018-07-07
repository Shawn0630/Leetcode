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

bool isMatch(string s, string p) {
     
}


int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		string str, pattern;
		istringstream iss(line);
		iss >> str >> pattern;
		cout << isMatch(str, pattern) << endl;
	}
}