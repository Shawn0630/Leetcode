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
// element in the vector should be DFS parameter.
long target;
void addOperatorsDFS(string num, string s, long preNum, long curRes, vector<string>& res) {
	//fou << "num = " << num << " s = " << s << " preNum = " << preNum << " curRes = " << curRes << endl;
	if(num.length() == 0 && curRes == target) {
		res.push_back(s);
		return;
	}

	for(int i = 1; i <= num.length(); i++) {
		string used = num.substr(0, i);
		string remain = num.substr(i);
		if(used.length() > 1 && used[0] == '0') return;
		long value = 0;
		for(int i = 0; i < used.length(); i++) {
			value = value * 10 + used[i] - '0';
		}
		if(s.length() == 0) {
			cout << "value = " << value << endl;
			addOperatorsDFS(remain, used, value, value, res);
		} else {
			addOperatorsDFS(remain, s + '+' + used, value, curRes + value, res);
			addOperatorsDFS(remain, s + '-' + used, -value, curRes - value, res);
			addOperatorsDFS(remain, s + '*' + used, value * preNum, (curRes - preNum) + value * preNum, res);
		}
	}
}


vector<string> addOperators(string num, int target) {
	vector<string> res;
    addOperatorsDFS(num, "", 0, 0, res);
    return res;
}

int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		string num;
		vector<string> res;
		istringstream iss(line);
		iss >> num;
		iss >> target;
		res = addOperators(num, target);
		for(int i = 0; i < res.size(); i++) {
			cout << res[i] << endl;
		}
		cout << endl;
	}
}