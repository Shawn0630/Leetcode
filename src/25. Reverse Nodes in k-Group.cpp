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

// [pre, next] return head 
// the last element of the k group(head) connect the first elemnt of the next k group.
ListNode* reverse(ListNode* pre, ListNode* end) {

   if(pre == NULL || pre->next == NULL) return pre;
    
    ListNode* head = pre->next;
    ListNode* cur = pre->next->next;

    while(cur != end) {
      ListNode* next = cur->next;
      cur->next = pre->next;
      pre->next = cur;
      cur = next;
    }

    head->next = end;
    return head;
 }



ListNode* reverseKGroup(ListNode* head, int k) {
  if(head == NULL) return NULL;
  
  ListNode* dummy = new ListNode(0);
  dummy->next = head;
  
  int counter = 0;
  ListNode* pre = dummy;
  ListNode* cur = dummy->next;
  
  while(cur != NULL) {
    while(counter < k && cur != NULL) {
      counter++;
      cur = cur->next;
    }

    //cout << "reverse(" << pre->val << ", " << cur->val << ")" << endl;
    if(counter == k) pre = reverse(pre, cur);
    //cur = cur->next;
    counter = 0;
  }  
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
