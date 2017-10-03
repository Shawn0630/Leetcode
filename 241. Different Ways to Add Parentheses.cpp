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


vector<int> diffWaysToCompute(string input) {
	  vector<int> res;
      return res;
}

int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		vector<int> res;
		res = diffWaysToCompute(line);
		for(int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
}