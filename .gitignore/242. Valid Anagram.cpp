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

bool isAnagram(string s, string t) {
     if(s.size() != t.size()) return false;
     map<char, int> s_map, t_map;
     for(int i = 0; i < s.size(); i++) {
     	s_map[s[i]]++;
     } 
     for(int i = 0; i < t.size(); i++) {
     	t_map[t[i]]++;
     }
     map<char,int>::iterator it;
     for(it = s_map.begin();it != s_map.end();++it) {
     	if(t_map[it->first] != it->second) return false;
     }
     return true;
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;

	while (getline(fin, line)) {
		if(line.size() == 0) break;
		string s1, s2;
		istringstream iss(line);
		iss >> s1 >> s2;
		cout << "The str1 is " << s1 << " the str2 is " << s2 << endl;
		cout << "isAnagram " << isAnagram(s1, s2) << endl;
	}	
}