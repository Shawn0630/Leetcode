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
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cctype>
#include <algorithm>

using namespace std;

ifstream fin("infile.txt");
ofstream fou("oufile.txt");

bool isPowerOfFour(int num) {
	if(num <= 0) return false; // integer = unsigned 32 bit
	if(num & (num - 1)) return false;
	if(num & 0x55555555) return true;
	return false;
}

int main() {
	string line;
	int num;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		iss >> num;
		cout << isPowerOfFour(num) << endl;
	}
}