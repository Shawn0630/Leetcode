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


//compute a^b % m
uint64_t pow(uint64_t a,uint64_t b, uint64_t m) {
   a %= m;
   uint64_t result = 1;
   while (b) {
      if (b & 1) {
         result = (result * a) % m;
      }
      a = (a * a) % m;
      b >>= 1;
   }
   return result;
}
// hash function (pattern[0] * power * p^0 + pattern[1] * power * p^1 + pattern[2] * power * p^2 + ... ) % M
uint64_t hashPattern(string pattern, uint64_t power, uint64_t p, uint64_t M) {
   uint64_t hash = 0;
   for (int i = 0; i < pattern.length(); ++i) {
      hash += power * pattern[i];
      hash %= M;
      power = (power * p) % M;
   }
   return hash;
}

//hashString match[start, start + 1, ..., start + length)
uint64_t hashString(string match, int start, int length, uint64_t& power, uint64_t p, uint64_t M) {
   uint64_t hash = 0;
   for(int i = 0; i < length; i++) {
      hash += power * match[(start + i) % match.length()];
      hash %= M;
      power = (power * p) % M;
   }
   return hash;
}

uint64_t nextHashString(string match, uint64_t prev_hash, int start, int length, uint64_t power, uint64_t p, uint64_t p_inv, uint64_t M) {
   uint64_t hash = 0;
   hash = prev_hash - match[start % match.length()];
   hash *= p_inv;
   hash += power * match[(start + length) % match.length()];
   hash %= M;
   return hash;
}

bool check(int index, string match, string pattern) {
   for (int i = 0; i < pattern.length(); ++i) {
      if (match[(i + index) % match.length()] != pattern[i]) {
         return false;
      }
   }
   return true;
}

int repeatedStringMatch(string A, string B) {
   static const uint64_t M = 1000000007;
   static const uint64_t p = 115; 
   static const uint64_t p_inv = pow(p, M - 2, M);
   cout << "p_inv = " << p_inv << endl;

   const auto q = (B.length() + A.length() - 1) / A.length();
    
   uint64_t b_hash = 0, power = 1;
   b_hash = hashPattern(B, power, p, M);

   uint64_t a_hash = 0; power = 1;
   a_hash = hashString(A, 0, B.length(), power, p, M);
   if (a_hash == b_hash && check(0, A, B)) {
      return q;
   }
        
   power = (power * p_inv) % M;
   for (int i = B.length(); i < (q + 1) * A.length(); ++i) {
      a_hash = nextHashString(A, a_hash, i - B.length(), B.length(), power, p, p_inv, M);
      if (a_hash == b_hash && check(i - B.length() + 1, A, B)) {
         return i < q * A.length() ? q : q + 1;
      }
   }
   return -1;
}



int main() {
   string line;
   while (getline(fin, line)) {
      if(line.size() == 0) break;
      string pattern, match;
      istringstream iss(line);
      iss >> match >> pattern;
      cout << repeatedStringMatch(match, pattern) << endl;
   }
}
