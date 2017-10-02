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

ListNode* deleteDuplicates(ListNode* head) {
	ListNode* tail = head;
	while(tail != NULL && tail->next != NULL) {
		if(tail->val == tail->next->val) {
			tail->next = tail->next->next;
		}
		else {
			tail = tail->next;
		}
	}
    return head;   
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
		cout << "After Duplication" << endl;
		printLinkedList(deleteDuplicates(fake_head->next));
	}	
}