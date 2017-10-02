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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* root;
	ListNode* cur;
	bool first = 1;
	int carry = 0;
	while(l1 != NULL && l2 != NULL) {
		int val = (l1->val + l2->val + carry) % 10;
		carry = (l1->val + l2->val + carry) / 10;
//		cout << "val = " << val << " carry = " << carry << endl;
		ListNode* node = new ListNode(val);
		if(first) {
			root = node;
			cur = root;
			first = 0;
		} else {
			cur->next = node;
			cur = node;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	while(l1 != NULL) {
		int val = (l1->val + carry) % 10;
		carry = (l1->val + carry) / 10;
		ListNode* node = new ListNode(val);
		cur->next = node;
		cur = node;
		l1 = l1->next;
	}
	while(l2 != NULL) {
		int val = (l2->val + carry) % 10;
		carry = (l2->val + carry) / 10;
		ListNode* node = new ListNode(val);
		cur->next = node;
		cur = node;
		l2 = l2->next;
	}
	if(carry != 0) {
		ListNode* node = new ListNode(carry);
		cur->next = node;
		cur = node;
	}
	return root;
}

void printList(ListNode* root) {
	bool first = true;
	while(root != NULL) {
		if(first) {
			first = false;
			cout << root-> val;
			root = root -> next;
		} else {
			cout << " -> " << root->val;
			root = root -> next;
		}
	}
	cout << endl;
}

void freeList(ListNode* root) {
	ListNode* node = root;
	while(node != NULL) {
		root = node -> next;
		delete node;
		node = root;
	}
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");

	string line;
	int num;
	ListNode* list1_root = NULL;
	ListNode* list2_root = NULL;
	bool first_node = true;
	bool first_list = true;

	while (getline(fin, line)) {
		if(line.size() == 0) break;
		istringstream iss(line);

		ListNode* prev;
//		cout << "line = " << line << " " << first_list << endl;
		if(first_list) {
			first_list = false;
			while(iss >> num) {	
//				cout << "read " << num << " in list 1" << endl;
				if(first_node) {
					list1_root = new ListNode(num);
					prev = list1_root;
					first_node = false;
				} else {
					ListNode* node = new ListNode(num);
					prev->next = node;
					prev = node;
				}
			} 
		} else {
			first_node = true;
			while(iss >> num) {
//				cout << "read " << num << " in list 2" << endl;	
				if(first_node) {
					list2_root = new ListNode(num);
					prev = list2_root;
					first_node = false;
				} else {
					ListNode* node = new ListNode(num);
					prev->next = node;
					prev = node;
				}
			}
			cout << "list 1 ";
			printList(list1_root);
			cout << "list 2 ";
			printList(list2_root); 
			cout << "Result ";
			printList(addTwoNumbers(list1_root, list2_root));
			cout << endl;
			freeList(list1_root);
			freeList(list2_root);
			list1_root = NULL;
			list2_root = NULL;
			first_list = true;
			first_node = true;
		}
	}
}
