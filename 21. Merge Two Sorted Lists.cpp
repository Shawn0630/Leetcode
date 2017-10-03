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

void printLinkedList(ListNode *head) {
	ListNode* tail = head;
	while(tail != NULL) {
		cout << tail->val << " ";
		tail = tail->next;
	}
	cout << endl;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* fake_head = new ListNode(0);
	ListNode* cur = fake_head;
	while(l1 != NULL && l2 != NULL) {
		if(l1->val < l2->val) {
			cur->next = l1;
			l1 = l1->next;
		} else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	while(l1 != NULL) {
		cur->next = l1;
		l1 = l1->next;
		cur = cur->next;
	}
	while(l2 != NULL) {
		cur->next = l2;
		l2 = l2->next;
		cur = cur->next;
	}
	return fake_head->next;
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;
	bool isFirst = true;
	ListNode* fake_head_1 = NULL;
	ListNode* fake_head_2 = NULL;
	ListNode* tail = NULL;

	while (getline(fin, line)) {

		cout << "line " << line << endl;
		if(line.size() == 0){ 
			fake_head_1 = NULL;
			fake_head_2 = NULL;
			getline(fin, line);
			if(line.size() == 0) break;	
		} else {
			int num;
			istringstream iss(line);
			if(isFirst) {
				fake_head_1 = new ListNode(0);
				tail = fake_head_1;
				isFirst = false;
			} else {
				fake_head_2 = new ListNode(0);
				tail = fake_head_2;
				isFirst = true;
			}
			while(iss >> num) {
				ListNode* node = new ListNode(num);
				tail->next = node;
				tail = tail->next;
			}

			if(fake_head_1 != NULL && fake_head_2 != NULL) {
				cout << "List 1:" << endl;
				printLinkedList(fake_head_1->next);
				cout << "List 2:" << endl;
				printLinkedList(fake_head_2->next);
				cout << "mergeTwoLists:" << endl;
				printLinkedList(mergeTwoLists(fake_head_1->next, fake_head_2->next));
			}
		}
	}	
}