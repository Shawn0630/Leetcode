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
    int min_index = 0;
    int max_index = min_index + 1;
    int total_profit = 0;
    while(min_index < prices.size() && max_index < prices.size()) {
    	while(min_index < prices.size() - 1 && prices[min_index] > prices[min_index + 1]) min_index++;
    	max_index = min_index + 1;
    	while(max_index < prices.size() - 1 && prices[max_index] < prices[max_index + 1]) max_index++;
    	if(max_index < prices.size() && min_index < prices.size()) {
//    		cout << "min_index = " << min_index << " prices[" << min_index << "] = " << prices[min_index] << " max_index = " << max_index << " prices[" << max_index << "] = " << prices[max_index] << endl;
    		total_profit += prices[max_index] - prices[min_index];
    	}
    	min_index = max_index + 1;
    }
    return total_profit;
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
	

	while (getline(fin, line)) {
		vector<int> prices;
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