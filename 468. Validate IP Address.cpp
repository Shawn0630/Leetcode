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

bool validIPV4Address(string IP) {
	IP = IP + ".";
	enum InputType {
        INVALID,    // 0
        ZERO,       // 1
        DIGIT,      // 2
        DOT,        // 3
        NUM_INPUTS  // 4
    };

    /*
    state

    0 initial
    1 ipv4 no accepting 0 and other digit
    2 ipv4 otherwise

	*/
    int transitionTable_IPV4[][NUM_INPUTS] = {
        -1, 1, 2, -1,
        -1, -1, -1, 0,
        -1, 2, 2, 0
    };

    int state = 0;
    InputType type = INVALID;
    int num = 0;
    int count = 0;


    for(int i = 0; i < IP.length(); i++) {
    	
    	if(IP[i] == '0') {
    		type = ZERO;
    	}
    	else if(IP[i] >= '1' && IP[i] <= '9') {
    		type = DIGIT;
    	}
    	else if(IP[i] == '.') {
    		type = DOT;
    	}

    	state = transitionTable_IPV4[state][type];
    	if(state == -1) return false;

    	switch(state){
    	case 0:
    		num = 0;
    		count++;
    		break;
    	case 1:
    		break;
    	case 2:
    		num = num * 10 + IP[i] - '0';
    		if(num > 255) return false;
    		break;
    	}
    }

    if(count != 4) return false;
    return true;
}

bool validIPV6Address(string IP) {

	IP = IP + ":";

	enum InputType {
        INVALID,    // 0
        ZERO,       // 1
	    VALID,      // 2 
       	COLON,      // 3
        NUM_INPUTS  // 4
    };

    /*
    state

    0 initial
    1 ipv6 0
    1 ipv6 0

	*/
    int transitionTable_IPV6[][NUM_INPUTS] = {
        -1, 1, 1, -1,
        -1, 1, 1, 0
    };

    int state = 0;
    InputType type = INVALID;
    int count = 0;
    int bitcount = 0;

    for(int i = 0; i < IP.length(); i++) {
    	if(IP[i] == '0') {
    		type = ZERO;
    	} 
    	else if(IP[i] >= '1' && IP[i] <= '9' || IP[i] >= 'A' && IP[i] <= 'F' || IP[i] >= 'a' && IP[i] <= 'f') {
    		type = VALID;
    	}
    	else if(IP[i] = ':') {
    		type = COLON;
    	}

    	state = transitionTable_IPV6[state][type];
    	if(state == -1) return false;

    	switch(state){
    	case 0:
    		count++;
    		bitcount = 0;
    		break;
    	case 1:
    		bitcount++;
    		if(bitcount > 4) return false;
    		break;
    	}
    }

    if(count != 8)return false;
    return true;
}

//first check IPV4
//then check IPV6
string validIPAddress(string IP) {
	string res = "";
	
	if(validIPV4Address(IP)) res = "IPv4";
	else if(validIPV6Address(IP)) res = "IPv6";
	else res = "Neither";
	
	return res;
}


int main() {
   string line;
   while (getline(fin, line)) {
   	  if(line.size() == 0) break;
      cout << validIPAddress(line) << endl;
   }
}