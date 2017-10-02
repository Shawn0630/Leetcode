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

ifstream fin("infile.txt");
ofstream fou("oufile.txt");

void generateParenthesisDFS(int left, int right, string out, vector<string>& res) {
	if(left == 0 && right == 0) {
		//fou << out << endl;
		res.push_back(out);
		return;
	}
	//fou << "left " << left << " right " << right << endl;
	if(left < right) generateParenthesisDFS(left, right - 1, out + ')', res);
	if(left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
    generateParenthesisDFS(n, n, "", res);// n right quote and left quote left
    return res;
}

int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		int num;
		iss >> num;
		vector<string> out = generateParenthesis(num);
		for(int i = 0; i < out.size(); i++) {
			cout << out[i] << endl;
		}
	}
}