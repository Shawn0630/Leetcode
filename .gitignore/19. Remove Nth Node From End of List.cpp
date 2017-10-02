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

void printLinkedList(ListNode *head) {
	ListNode* tail = head;
	while(tail != NULL) {
		cout << tail->val << " ";
		tail = tail->next;
	}
	cout << endl;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* fake_head = new ListNode(0);
	fake_head->next = head;
	ListNode* tail1 = fake_head;
	ListNode* tail2 = fake_head;
	int i = 0;
	while(tail1 != NULL) {
		tail1 = tail1 -> next;
		if(i <= n) i++;
		else {
			cout << "change" << endl;
			tail2 = tail2 -> next;
		}
	}
//	cout << "tail2->val = " << tail2->val << " (tail2->next)->next = " << (tail2->next)->next->val<< endl;
	tail2->next = (tail2->next)->next;
	head = fake_head->next;
//	cout << "head->val = " << head->val << endl;
    return fake_head->next;
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
		ListNode* l = removeNthFromEnd(fake_head->next, 4);
		printLinkedList(l);
	}	
}