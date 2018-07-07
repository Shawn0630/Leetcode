#include <iostream>
#include <fstream>


using namespace std;

ifstream fin("infile.txt");
ofstream fou("oufile.txt");

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 void swap(ListNode* connector, ListNode* left, ListNode* right) {
 	connector->next = right;
 	right->next = left;
 }

 ListNode* swapPairs(ListNode* head) {
 	ListNode* dummy = new ListNode(0);
 	dummy->next = head;
  ListNode* pre = dummy;
 	ListNode* cur = dummy->next;
 	while(cur != NULL && cur->next != NULL) {
    cout << pre->val << " " << cur->val << " " << cur->next->val << endl;
    ListNode* nxt = cur->next->next;
 		swap(pre, cur, cur->next);
    pre = cur;
    cur = nxt;
 	}
  pre->next = cur;
 	return dummy->next;
 }

 void printLinkedList(ListNode* head) {
 	bool isFirst = true;
 	while(head != NULL) {
 		if(isFirst)isFirst = false;
 		else cout << "->";
 		cout << head->val;
 		head = head->next;
 	}
 	cout << endl;
 }

 int main() {
 	ListNode* first = new ListNode(1);
 	ListNode* second = new ListNode(2);
 	ListNode* third = new ListNode(3);
 	ListNode* forth = new ListNode(4);
 	ListNode* fifth = new ListNode(5);
 	ListNode* sixth = new ListNode(6);
 	ListNode* seventh = new ListNode(7);


 	first->next = second;
 	second->next = third;
 	third->next = forth;
 	forth->next = fifth;
 	fifth->next = sixth;
 	sixth->next = seventh;

 	ListNode* head = swapPairs(first);

 	printLinkedList(head);
 }
