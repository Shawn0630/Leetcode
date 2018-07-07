#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int findComplement(int num) {
        bool flag = false;
        for(int i = 31; i >= 0; i--) {
        	if(num & (1 << i)) flag = true;
        	if(flag) {
        		num ^= (1 << i);
        	}
        }
        return num;
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;
	int a;
	while(getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		iss >> a;
		fou << findComplement(a) << endl;
	}
}