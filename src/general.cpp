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

string findNumber(vector<int> arr, int k) {
    int pos = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == k) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        return "NO";
    } else {
        return "YES";
    }
}

vector < int > oddNumbers(int l, int r) {
    vector<int> res;

    for (int i = l; i <= r; i++) {
        if (i % 2 == 0) continue;
        res.push_back(i); 
    }

    return res;
}

vector<string> braces(vector<string> values) {
    vector<string> res;
    for (int testCase = 0; testCase < values.size(); testCase++) {
        stack<char> parentheses;
        string s = values[testCase];
        bool isValid = true;
	    for(int i = 0; i < s.size(); i++) {
		    if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
			    parentheses.push(s[i]);
		    } else if(s[i] == ')') {
			    if(!parentheses.empty() && parentheses.top() == '(') {
				    parentheses.pop();
			    } else {
                    res.push_back("NO");
                    isValid = false;
                    break;
                };
		    } else if(s[i] == '}') {
			    if(!parentheses.empty() && parentheses.top() == '{') {
				    parentheses.pop();
			    } else {
                    res.push_back("NO");
                    isValid = false;
                    break;
                }
		    } else if(s[i] == ']') {
			    if(!parentheses.empty() && parentheses.top() == '[') {
				    parentheses.pop();
			    } else {
                    res.push_back("NO");
                    isValid = false;
                    break;
                };
		    }
	    }
        if (!isValid) continue;
	    if(!parentheses.empty()) {
            res.push_back("NO");
        } else {
            res.push_back("YES");
        };
    }

    return res;
}

int moves(vector<int> a) {
    int i = 0;
    int j = a.size() - 1;
    int move = 0;

    while(i <= j) {
        while (i < a.size() && a[i] % 2 == 0) i++;
        while (j >= i && a[j] % 2 != 0) j--;
        if (i < j) {    
            move++;
            i++;
            j--;
        }
    }

    return move;
}