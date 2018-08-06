#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <cctype>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

int sizeOfList(ListNode* head) {
    ListNode* cur = head;
    int count = 0;
    while( cur != NULL) {
        count++;
        cur = cur -> next;
    }

    return count;
}

ListNode* lastOfList(ListNode* head, int n) {
    ListNode* cur = head;
    ListNode* last = NULL;
    int i = 0;

    while (cur != NULL) {
        cur = cur -> next;
        if (i < n) {
            i++;
        } else if (i == n) {
            last = head;
            i++;
        } else {
            last = last ->next;
        }
    }

    return last;
}

ListNode* rotateRight(ListNode* head, int k) {
    int size = sizeOfList(head);
    if (size == 0) {
        return NULL;
    }
    int last = k % size;

    ListNode* node = lastOfList(head, last);
    ListNode* newHead = node->next;
    node->next = NULL;
    if (newHead == NULL) {
        return head;
    }

    ListNode* cur = newHead;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = head;

    return newHead;
}