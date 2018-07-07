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

// be careful to the NULL case check first
ListNode* reverse(ListNode* head) {
	if(head == NULL) return NULL:
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* pre = dummy;
	ListNode* cur = head;
	while(cur != NULL) {
		ListNode* next = cur->next;
		cur->next = pre->next;
		pre->next = cur;
		cur = next;
	}
	head->next = NULL;
	return dummy->next;
}

ListNode* findMidNode(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;

	while(fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
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

 void reorderList(ListNode* head) {
 	if(head == NULL) return;
 	ListNode* mid = findMidNode(head);
 	if(mid == NULL) return;
 	ListNode* second = mid->next;
 	second = reverse(second);
 	ListNode* first = head;
 	mid->next = NULL;
 	while(second != NULL) {
 		ListNode* firstNext = first->next;
 		ListNode* secondNext = second->next;
 		first->next = second;
 		second->next = firstNext;
 		first = firstNext;
 		second = secondNext;
 	}  
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

 	reorderList(first);
 	printLinkedList(first);


 }
