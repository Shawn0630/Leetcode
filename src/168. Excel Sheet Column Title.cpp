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

string convertToTitle(int n) {
	string res;
	while(n != 0) {
		n = n - 1;
		int m = n % 26;
//		cout << "m = " << m << " char = " << char('A' + m) << endl;
		res = char('A' + m) + res;
		n = n / 26;
    }
    return res;
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;

	while (getline(fin, line)) {
		if(line.size() == 0) break;
		int num;
		istringstream iss(line);
		iss >> num;
		cout << "The num is " << num << endl;
		cout << "Title is " << convertToTitle(num) << endl;
	}	
}