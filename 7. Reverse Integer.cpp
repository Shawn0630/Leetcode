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
#include <queue>
#include <cctype>
#include <algorithm>

using namespace std;

ifstream fin("infile.txt");
ofstream fou("oufile.txt");


int reverse(int x) {
	int64_t res = 0;
	while(x != 0) {
		int num = x % 10;
		res = res * 10 + num;
		x = x / 10;
	}
	if ((int64_t)((int32_t)res) != res) return 0;
    return res;
}



int main() {
   string line;
   int64_t tmp = 2147483648;
   int temp = 2147483648;
   cout << tmp << ", " << (int64_t)((int32_t)tmp) << ", " << temp << endl;
   while (getline(fin, line)) {
      if(line.size() == 0) break;
      int x;
      istringstream iss(line);
      iss >> x;
      cout << reverse(x) << endl;
   }
}