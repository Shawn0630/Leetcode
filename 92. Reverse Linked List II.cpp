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

void reverseList(ListNode* left, ListNode* right) {
 	ListNode* cur = left->next;
 	ListNode* prev = left;
 	ListNode* next = NULL;
 	while(cur != right) {
 		next = cur->next;
 		cur->next = prev;
 		prev = cur;
 		cur = next;
 	}
 	left->next->next = right;
 	left->next = prev;
}

void printLinkedList(ListNode *head) {
	ListNode* tail = head;
	while(tail != NULL) {
		cout << tail->val << " ";
		tail = tail->next;
	}
	cout << endl;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
     int size = n - m;
     ListNode* fake_head = new ListNode(0);
     fake_head->next = head;
     ListNode* left = fake_head;
     ListNode* right = fake_head;
     int count = 0;
     for(int i = 0; i < n; i++) {
     	if(count <= size) count++;
     	else left = left->next;
//     	cout << "right = " << right->val << endl;
     	right = right->next;
     }
     right = right->next;
//     cout << "left = " << left->val << " right = " << right->val << endl;
     reverseList(left, right);
     head = fake_head->next;
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
		ListNode* l = reverseBetween(fake_head->next, 1, 3);
		printLinkedList(l);
	}	
}