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

// exchange left and right return the last element of the reversed linked list
 ListNode* swap(ListNode* connector, ListNode* left, ListNode* right) {
 	connector->next = right;
 	right->next = left;
  return left;
 }
// reverse the list of length k and return the last element of the reversed linked list
 ListNode* reverse(ListNode* head, ListNode* tail) {
  
 }

// a > 0 => a >= 1
 ListNode* last(ListNode* head, int length) {
   while(length > 1) {
     if(head == NULL) return NULL;
     head = head->next;
     length--;
   }
   return head;
 }

ListNode* reverseKGroup(ListNode* head, int k) {
  ListNode* dummy = new ListNode(0);
  dummy->next = head;
  ListNode* pre = dummy;
  ListNode* cur = dummy->next;
  ListNode* nxt = last(cur, k);
  while(pre != NULL) {
    pre = reverse(cur, k);
    pre->next = nxt;
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

 	ListNode* head = reverseKGroup(first, 2);
  printLinkedList(head);

  first->next = second;
  second->next = third;
  third->next = forth;
  forth->next = fifth;
  fifth->next = sixth;
  sixth->next = seventh;
  head = reverseKGroup(first, 3);
  printLinkedList(head);


 }
