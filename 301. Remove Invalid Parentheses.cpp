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

ifstream fin("infile.txt");
ofstream fou("oufile.txt");
int minCount = INT_MAX;


bool isValidParentheses(string s) {
	int left = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(') left++;
		else if(s[i] == ')') left--;
		if(left < 0) return false;
	}
	if(left > 0) return false;
	else return true;
}

string string_erase_at(string s, int pos, int length) {
	if(pos + length > s.length()) return s;
	string::iterator it = s.begin();
	for(int i = 0; it != s.end(); it++, i++) {
		if(i == pos) {
			for(int j = 0; j < length; j++) {
				it = s.erase(it);
			}
			break;
		}
	}
	return s;
}

void removeInvalidParenthesesDFS(string s, int index, int count, unordered_map<string, int>& m) {
	if(!isValidParentheses(s)) {
		if(index + 1 < s.length()) {
			//fou << "search2 " << s << " " << index << endl; 
			removeInvalidParenthesesDFS(s, index + 1, count, m);
		}
		if(index < s.length()) {
			//fou << "search1 " << string_erase_at(s, index, 1) << " " << index << endl; 
			if(count + 1 <= minCount) removeInvalidParenthesesDFS(string_erase_at(s, index, 1), index, count + 1, m);
		}
	} else {
		if(!(m.find(s) == m.end())) {
			if(count < m[s]) m[s] = count;
		} else m[s] = count;
		if(count < minCount) minCount = count;
	}
	//fou << "Return" << endl;
	return;
}

vector<string> removeInvalidParenthesesBFS(string s) {
	vector<string> res;
	queue<string> q;
	unordered_map<string, int> m;
	int step = 0;
	bool found = false;
	
	q.push(s);
	m[s] = step;
	while(!q.empty()) {
		fou << "search " << s << endl;
		s = q.front(); 
		q.pop();
		if(isValidParentheses(s)) {
			found = true;
			res.push_back(s);
		} else {
			if(found) continue;
			step++;
			for(int i = 0; i < s.length(); i++) {
				if (s[i] != '(' && s[i] != ')') continue;
				string t = s.substr(0, i) + s.substr(i + 1);
				fou << "t = " << t << endl;
				if(m.find(t) == m.end()) {
				m[t] = step;
				q.push(t);
			}
			}
			
		}
	}
	return res;

}

vector<string> removeInvalidParentheses(string s) {
      /*vector<string> out;
      unordered_map<string, int> m;
      unordered_map<string, int>::iterator it;
      removeInvalidParenthesesDFS(s, 0, 0, m);
      for(it = m.begin(); it != m.end(); it++) {
      	if(it->second == minCount) out.push_back(it->first);
      }
      return out;*/

	return removeInvalidParenthesesBFS(s);
}


int main() {
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		vector<string> res = removeInvalidParentheses(line);
		for(int i = 0; i < res.size(); i++) {
			cout << res[i] << " " << endl;
		}
		cout << endl;
	}
}