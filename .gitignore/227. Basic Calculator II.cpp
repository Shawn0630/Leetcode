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
	if(num_stack.size() == 1) return num_stack.top();
	int right = num_stack.top();
	num_stack.pop();
	char op = op_stack.top();
	op_stack.pop();
	if(op == '+') return calculateStack(num_stack, op_stack) + right;
	else if(op == '-') return calculateStack(num_stack, op_stack) - right;
}

int calculate(string s) {
	int last_num = 0;
	stack<int> num_stack;
	stack<char> op_stack;
	char op;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == ' ') continue;
		else if(s[i] == '+' || s[i] == '-') op_stack.push(s[i]);
		else if(s[i] == '*' || s[i] == '/') op = s[i];
		else {
			while(i < s.length() && s[i] >= '0' && s[i] <='9') {
				last_num = last_num * 10 + s[i] - '0';
				i++;
			}
			num_stack.push(last_num);
			last_num = 0;
			i--;
			if(op == '*' || op == '/') {
				int right = num_stack.top();
				num_stack.pop();
				int left = num_stack.top();
				num_stack.pop();
				if(op == '*') num_stack.push(left * right);
				else if(op == '/') num_stack.push(left / right);
				op = 'n';
			}
		}
	}
	return calculateStack(num_stack, op_stack);
}

/*
int calculate(string s) {
        stack<int> num;
        stack<char> op;
        int i = 0;
        while(i < s.size())
        {
            while(i < s.size() && s[i] == ' ')
                i ++;
            if(i == s.size())
                break;
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                op.push(s[i]);
                i ++;
            }
            else
            {
                int n = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9')
                {
                    n = n * 10 + (s[i]-'0');
                    i ++;
                }
                num.push(n);
                if(!op.empty() && (op.top() == '*' || op.top() == '/'))
                {
                    int n2 = num.top();
                    num.pop();
                    int n1 = num.top();
                    num.pop();
                    if(op.top() == '*')
                        num.push(n1 * n2);
                    else
                        num.push(n1 / n2);
                    op.pop();
                }
            }
        }
        // '+'/'-' in order
        if(!op.empty())
        {
            // reverse num and op
            stack<int> num2;
            while(!num.empty())
            {
                num2.push(num.top());
                num.pop();
            }
            num = num2;
            stack<char> op2;
            while(!op.empty())
            {
                op2.push(op.top());
                op.pop();
            }
            op = op2;
            
            while(!op.empty())
            {
                // pay attention to the operands order!
                int n1 = num.top();
                num.pop();
                int n2 = num.top();
                num.pop();
                if(op.top() == '+')
                    num.push(n1 + n2);
                else
                    num.push(n1 - n2);
                op.pop();
            }
        }
        return num.top();
    }*/

int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		cout << calculate(line) << endl;
	}
}