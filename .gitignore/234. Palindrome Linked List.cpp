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

ListNode* findMidNode(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while(fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

void printLinkedList(ListNode *head) {
	ListNode* tail = head;
	while(tail != NULL) {
		cout << tail->val << " ";
		tail = tail->next;
	}
	cout << endl;
}

ListNode* reverseList(ListNode* head) {
	ListNode* prev = NULL;
	ListNode* cur = head;
	ListNode* next = NULL;
	while(cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

bool isPalindrome(ListNode* head) {
	ListNode* midNode = findMidNode(head);
	cout << midNode->val << endl;
	ListNode* reverse = reverseList(midNode);
//	printLinkedList(reverse);
	ListNode* tail = head;
	while(tail != midNode) {
		if(tail->val != reverse->val)return false;
		tail = tail->next;
		reverse = reverse->next;
	}
	return true;
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
		cout << "isPalindrome " << isPalindrome(fake_head->next) << endl;
	}	
}