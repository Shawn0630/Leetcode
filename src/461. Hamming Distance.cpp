#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int hammingDistance(int x, int y) {
    int res = x ^ y;
    int count = 0;
    for(int i = 0; i < 32; i++) {
    	if((res & 1) == 1) {
    		count++;
    	}
    	res >>= 1;
    }
    return count;
}

int main(int argc, char const *argv[])
{
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;
	int a, b;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		iss >> a >> b;
		fou << hammingDistance(a, b) << endl;
	}
	return 0;
}

