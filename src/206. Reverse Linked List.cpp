#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
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

ListNode* reverseList(ListNode* head) {
   if(head == NULL) return NULL;
//   ListNode* fake_head = new ListNode(0);
//   fake_head->next = head;
   ListNode* prev = NULL;
   ListNode* cur = head;
   ListNode* next;
   while(cur != NULL) {
   	    next = cur->next;
   		cur->next = prev;
//   	cout << "cur = " << cur->val << endl;
   		prev = cur;
   		cur = next;
   }
//   head->next = NULL;
//   head = prev;
//   cout << "prev = " << prev->val << endl;
   return prev;
}

ListNode* reverseList_recursion(ListNode* head) {

}

void printLinkedList(ListNode *head) {
	ListNode* tail = head;
	while(tail != NULL) {
		cout << tail->val << " ";
		tail = tail->next;
	}
	cout << endl;
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;
	while (getline(fin, line)) {
		if(line.size() == 0) break;
		ListNode *fake_head = new ListNode(0);
		ListNode *tail = fake_head;
		int num;
		istringstream iss(line);
		while(iss >> num) {
			ListNode* node = new ListNode(num);
			tail->next = node;
			tail = tail->next;
		}
		printLinkedList(fake_head->next);
		ListNode* l = reverseList(fake_head->next);
		printLinkedList(l);
	}	
}