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

int calculateStack(stack<int>& num_stack, stack<char>& op_stack) {
	int right = num_stack.top();
	num_stack.pop();
	if(op_stack.empty()) return right;
	char op = op_stack.top();
	op_stack.pop();
	if(op == '+') return calculateStack(num_stack, op_stack) + right;
	else if(op == '-') return calculateStack(num_stack, op_stack) - right;
	else if(op == '(') return right;
}

int calculate(string s) {
	stack<int> num_stack;
	stack<char> op_stack;
	int last_num = 0;
	bool have_num = false;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == ' ') {
			if(have_num) {
				num_stack.push(last_num);
				last_num = 0;
				have_num = false;
			}
		}
		else if(s[i] == '(') op_stack.push(s[i]);
		else if(s[i] == ')') {
			if(have_num) {
			num_stack.push(last_num);
			last_num = 0;
			have_num = false;
			}
			num_stack.push(calculateStack(num_stack, op_stack));
		}
	    else if(s[i] >= '0' && s[i] <= '9'){
	    	have_num = true;
	    	last_num = last_num * 10 + s[i] - '0';
	    }
	    else if(s[i] == '+' || s[i] == '-') {
	    	if(have_num) {
	    		num_stack.push(last_num);
				last_num = 0;
				have_num = false;
			}
			op_stack.push(s[i]);
		}
	}
	if(have_num) {
		num_stack.push(last_num);
		last_num = 0;
		have_num = false;
	}
	return calculateStack(num_stack, op_stack);
}

int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		cout << calculate(line) << endl;
	}
}