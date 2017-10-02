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

bool isPowerOfThree(int n) {
	if(n <= 0) return false;
	if(n % 3 != 0) return false;
	if(n / 3 == 1 && n % 3 == 0) return true;
	return isPowerOfThree(n / 3);

        
}

int main() {
	string line;
	int num;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		iss >> num;
		cout << isPowerOfThree(num) << endl;
	}
}