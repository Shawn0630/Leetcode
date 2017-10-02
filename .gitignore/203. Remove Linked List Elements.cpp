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


ListNode* removeElements(ListNode* head, int val) {
	ListNode* fake_head = new ListNode(0);
	fake_head->next = head;
	ListNode* node = fake_head;
	while(node->next != NULL) {
		if((node->next)->val == val) {
			node->next = (node->next)->next;
		} else {
			node = node->next;
		}
	}
	return fake_head->next;
}