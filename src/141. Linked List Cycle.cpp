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

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) {
      	val = x;
      	next = NULL;
      }
};

bool hasCycle(ListNode *head) {
	if(head == NULL || head -> next == NULL) return NULL;
	ListNode* slow = head;
	ListNode* fast = head;
	do {	
		slow = slow -> next;
		fast = fast -> next -> next;
	}while(fast != NULL && fast -> next != NULL && fast != slow);
	if(fast == NULL || fast -> next == NULL) return false;
	else return true;
}

int main() {
	/*string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);
		int num;
		ListNode* dummy = new ListNode(0);
		ListNode* next = dummy;
		while(iss >> num) {
			ListNode* node = new ListNode(num);
			next->next = node;
			next = next->next;
		}*/
		/*next = dummy -> next;
		while(next != NULL) {
			cout << next->val << " ";
			next = next->next;
		}
		cout << endl;*/
		ListNode* dummy = new ListNode(0);
		ListNode* l1 = new ListNode(1);
		ListNode* l2 = new ListNode(2);
		dummy->next = l1;
		l1->next = l2;
		cout << hasCycle(dummy->next) << endl;
}