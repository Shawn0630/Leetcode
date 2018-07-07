#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

vector<string> fizzBuzz(int n) {
	vector<string> res;
	string fizz = "Fizz";
	string buzz = "Buzz";
	int a[n] = ;

	return res;
        
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");

	int i = 0;
	string line;
	vector<string> result;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		iss >> i;
		result = fizzBuzz(i);
		for(int i = 0; i < result.size(); i++) {
			cout << "Result: " << result[i] << endl; 
		}
	}
}