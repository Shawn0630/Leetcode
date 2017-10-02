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

ListNode* mergeList(ListNode* left, ListNode* right) {
	ListNode* cur = new ListNode(0);
	ListNode* fake_head = cur;
	while(left != NULL && right != NULL) {
		if(left->val < right->val) {
			cur->next = left;
			left = left->next;
		} else {
			cur->next = right;
			right = right->next;
		}
		cur = cur->next;
	}
	while(left != NULL) {
		cur->next = left;
		left = left->next;
		cur = cur->next;
	}
	while(right != NULL) {
		cur->next = right;
		right = right->next;
		cur = cur->next;
	}
	return fake_head->next;
}

ListNode* findMid(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	ListNode* prev = head;
	while(fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}
	return prev;//mid is the prev one of the middle point.
}

ListNode* sortList(ListNode* head) {
//	cout << "Sort List" << endl;
//	printLinkedList(head);
	if(head == NULL || head->next == NULL) return head;
	ListNode* middle = findMid(head);
//	cout << "Right List" << endl;
//	printLinkedList(middle->next);
	ListNode* right = sortList(middle->next);
	middle->next = NULL;//cut the linked list into left and right
//	cout << "Left List" << endl;
//	printLinkedList(head);
	ListNode* left = sortList(head);
	ListNode* merged = mergeList(left, right);
	return merged;
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
		cout << "Input List " << endl;
		printLinkedList(fake_head->next);
		ListNode* sorted = sortList(fake_head->next);
		cout << "After sorting list" << endl;
		printLinkedList(sorted);
	}	
}