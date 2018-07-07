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

 ListNode* insertionSortList(ListNode* head) {
   ListNode* dummy = new ListNode(0);
   dummy->next = head;
   ListNode* pre_a = dummy;
   ListNode* cur_a = dummy->next;
   while(cur_a != NULL && cur_a->next != NULL) {

     int min = cur_a->val;
     ListNode* min_pre_b = pre_a;
     ListNode* min_cur_b = cur_a;

     ListNode* pre_b = cur_a;
     ListNode* cur_b = cur_a->next;
     while(cur_b != NULL) {
       if(cur_b->val < min) {
         min = cur_b->val;
         min_pre_b = pre_b;
         min_cur_b = cur_b;
       }
       pre_b = pre_b->next;
       cur_b = cur_b->next;
     }
     cout << pre_a->val << " " << cur_a->val << " " << min_pre_b->val << " " << min_cur_b->val << endl;

     if(cur_a != min_cur_b && min_cur_b != NULL) {
       pre_a->next = min_cur_b;
       min_pre_b->next = cur_a;

       ListNode* temp = cur_a->next;
       cur_a->next = min_cur_b->next;
       min_cur_b->next = temp;
     }

     pre_a = pre_a->next;
     cur_a = pre_a->next;
    }
    return dummy->next;
  }

 int main() {
 	ListNode* first = new ListNode(1);
 	// istNode* second = new ListNode(2);
 	// ListNode* third = new ListNode(3);
 	// ListNode* forth = new ListNode(4);
 	// ListNode* fifth = new ListNode(5);
 	// ListNode* sixth = new ListNode(7);
 	// ListNode* seventh = new ListNode(6);


 	// first->next = second;
 	// second->next = third;
 	// third->next = forth;
 	// forth->next = fifth;
 	// fifth->next = sixth;
 	// sixth->next = seventh;

 	ListNode* head = insertionSortList(first);
  printLinkedList(head);
 }
