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

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if(lists.size() == 0) return NULL;
	if(lists.size() == 1) return lists[0];
	ListNode* last = mergeTwoLists(lists[0], lists[1]);
	for(int i = 2; i < lists.size(); i++) {
		last = mergeTwoLists(last, lists[i]);
	}
	return last;     
}

ListNode* helper(vector<ListNode*>& lists, int left, int right) {
//	cout << "left = " << left << " right = " << right << endl;
	if(right - left == 2) {
		return mergeTwoLists(lists[left], lists[left + 1]);
	}
	if(right - left == 1) {
		return mergeTwoLists(lists[left], NULL);
	}
	int mid = left + (right - left) / 2;
	ListNode* l1 = helper(lists, left, mid);
	ListNode* l2 = helper(lists, mid, right);
	return mergeTwoLists(l1, l2);

 // if(left < right)  //0, size - 1
 //    {  
 //        int mid = (left + right) / 2;  
 //        return merge(helper(lists,left,mid),helper(lists,mid + 1,right));  
 //    }  
 // return lists[l];
}

ListNode* mergeKLists_2(vector<ListNode*>& lists) {
	if(lists.size() == 0) return NULL;
	if(lists.size() == 1) return lists[0];
	return helper(lists, 0, lists.size());
}

int main() {
	ifstream fin("infile.txt");
	ofstream fou("oufile.txt");
	string line;
	bool isFirst = true;
	ListNode* fake_head = NULL;
	ListNode* tail = NULL;
	vector<ListNode*> v;
	while(getline(fin, line)) {
//		cout << "1 line = " << line << " line.size() = " << line.size() << endl;
		if(line.size() == 1) {
//			cout << "list.size() " << v.size() << endl;
			for(int i = 0; i < v.size(); i++) {
				cout << "Unsorted List " << i << endl;
				printLinkedList(v[i]);
			}
			ListNode* l = mergeKLists_2(v);
			cout << "Sorted List" << endl;
			printLinkedList(l);
			v.clear();
			getline(fin, line);
//			cout << "2 line = " << line << " line.size() = " << line.size() << endl;
			if(line.size() == 0) break;
		}
		int num;
		istringstream iss(line);
		fake_head = new ListNode(0);
		tail = fake_head;
		while(iss >> num) {
			ListNode* node = new ListNode(num);
			tail->next = node;
			tail = tail->next;
		}
		v.push_back(fake_head->next);
	}
}
