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

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


void deleteNode(ListNode* node) {
	if(node == NULL) return;
	node->val = (node->next)->val;
	node->next = (node->next)->next;
	//free(node->next);
}


int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
}