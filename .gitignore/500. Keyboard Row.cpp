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

vector<string> findWords(vector<string>& words) {
    char row1[] = {'q','w','e','r','t','y','u','i','o','p'};    
    char row2[] = {'a','s','d','f','g','h','j','k','l'};    
    char row3[] = {'z','x','c','v','b','n','m'}; 

    map<char, int> myMap;
    bool flag = true; 
    int row = 0;
    vector<string> res;

    for(int i = 0; i < (sizeof(row1) / sizeof(row1[0])); i++) {
    	myMap.insert(pair<char, int>(row1[i], 1));
    }
    for(int i = 0; i < (sizeof(row2) / sizeof(row2[0])); i++) {
    	myMap.insert(pair<char,int>(row2[i], 2));
    }
    for(int i = 0; i < (sizeof(row3) / sizeof(row3[0])); i++) {
    	myMap.insert(pair<char, int>(row3[i], 3));
    }

    for(int i = 0; i < words.size(); i++) {
    	flag = true;
    	int j = 0;
    	string s = words[i];
    	transform(words[i].begin(),words[i].end(),s.begin(),::tolower);
    	for(j = 0; j < s.length(); j++) {
    		if(flag) {
    			flag = false;
    			row = myMap[s[j]];
    		} else {
    			if(row != myMap[s[j]]) break;
    		}
		}
		if(j == words[i].length()) {
			res.push_back(words[i]);
		}
    }
    return res;
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");

	string line;
	vector<string> in;
	vector<string> ou;

	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		do {
        	string sub;
        	iss >> sub;
        	if(!sub.empty()) {
        		cout << "Substring: " << sub << endl;
        		in.push_back(sub);
        	}
    	} while (iss);

    	ou = findWords(in);

    	for(int i = 0; i < ou.size(); i++) {
    		cout << "Result: " << ou[i] << endl;
    	}

	}
}