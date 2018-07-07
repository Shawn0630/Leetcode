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

bool isPalindrome(int x) {
   if(x < 0) return false;
   int div = 1;
   int first, last,remain;
   while(x / div >= 10) div = div * 10;
   while(x > 0) {
   		first = x / div;
   		last = x % 10;
   		if(first != last) return false;
   		x = (x % div) / 10;
   		div = div / 100;
   }
   return true;
}


int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		int num;
		istringstream iss(line);
		iss >> num;
		cout << isPalindrome(num) << endl;
	}
}