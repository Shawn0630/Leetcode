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

int getSum(int a, int b) {
	cout << "Calculate " << a << " + " << b << endl;
	int ans = 0, carry = 0;
	for(int i = 0; i < 32; i++) {
		bool flag = false;
		int lower_a = a & 1;
		int lower_b = b & 1;
		ans |= (lower_a ^ lower_b ^ carry) << i;
		cout << "lower_a = " << lower_a << " lower_b = " << lower_b << " ans = " << ans << endl;
		carry =  (carry & lower_a) | (carry & lower_b) | (lower_a & lower_b);
		a = a >> 1;
		b = b >> 1;
	}
	return ans;
}

/*int getSum(int a, int b) {
	while (b != 0) {
		int c = a & b; //carry
		a ^= b; //add 
		b = c << 1;
	}
	return a;
}*/

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");

	string line;

	while (getline(fin, line)) {
		int num1 = 0, num2 = 0;
		if(line.size() == 0) break;
		istringstream iss(line);
		iss >> num1 >> num2;
		cout << "The result is = " << getSum(num1, num2) << endl;   
    }
}