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

int maxProfit(vector<int>& prices) {
	if(prices.size() == 0) return 0;
	int min = prices[0];
	int max_after_min = prices[0];
	int profit = 0;
	for(int i = 1; i < prices.size(); i++) {
//		cout << "prices[" << i << "] = " << prices[i] << endl;
		if(prices[i] < min) {
//			cout << "update min = prices[" << i << "] = " << prices[i] << endl;
			min = prices[i];
		} else {
			if(prices[i] - min > profit)
			profit = prices[i] - min;
		}
	}
	return profit;
}

void printVector(vector<int> prices) {
	for(int i = 0; i < prices.size(); i++) {
		cout << prices[i] << " ";
	}
	cout << endl;
}


int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;
	vector<int> prices;

	while (getline(fin, line)) {
		if(line.size() == 0) break;
		int num;
		istringstream iss(line);
		while(iss >> num) {
			prices.push_back(num);
		}
		printVector(prices);
		cout << "maxProfit = " << maxProfit(prices) << endl;
	}	
}