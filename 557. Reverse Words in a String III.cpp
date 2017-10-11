#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
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

/*vector<string> &split( const string &str, const string &delimiters, vector<string> &elems, bool skip_empty = true ) {
    string::size_type pos, prev = 0;
    while ( ( pos = str.find_first_of(delimiters, prev) ) != string::npos ) {
        if ( pos > prev ) {
            if ( skip_empty && 1 == pos - prev ) break;
            elems.emplace_back( str, prev, pos - prev );
        }
        prev = pos + 1;
    }
    if ( prev < str.size() ) elems.emplace_back( str, prev, str.size() - prev );
    return elems;
}*/

void reverseString(string& s, int start, int end) {
	char temp;
	for(int i = 0; i < (end - start) / 2; i++) {
		temp = s[start + i];
		s[start + i] = s[end - i - 1];
		s[end - i - 1] = temp;
	}
}

string reverseWords(string s) {
	string res = "";
	bool first = true;
	istringstream buf(s);
    istream_iterator<string> beg(buf), end;
    vector<string> tokens(beg, end);
	//cout << tokens.size() << endl;
	for(int i = 0; i < tokens.size(); i++) {
		if(first) first = false;
		else res += " ";
		//cout << tokens[i] << endl;
		reverseString(tokens[i], 0, tokens[i].length());
		//cout << tokens[i] << endl;
		res += tokens[i];
	}
	return res;       
}


/*int main() {
    string str( "I love u" );
    vector<string> result;
    for ( const auto &s : split( str, " ", result ) )
        std::cout << s << " ";
    std::cout << std::endl;
}*/

int main() {
   string line;
   while (getline(fin, line)) {
   	  if(line.size() == 0) break;
      cout << reverseWords(line) << endl;
   }
}