/*
 * leetcode Remove Duplicates from Sorted List
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "listnode.h"
using namespace std;

ListNode *deleteDuplicates(ListNode *head)
{
    if (!head || !head->next) return head;
    ListNode* p1 = head->next; // p1 scan the whole list
    ListNode* p2 = head; // p2 record the unique list element

    while (p1)
    {
        if (p1->val != p2->val)
        {
            p2 = p2->next;
            p2->val = p1->val;
        }
        p1 = p1->next;
    }

    ListNode* removed = p2->next;
    p2->next = NULL;
    while (removed)
    {
        ListNode* p = removed->next;
        delete removed;
        removed = p;
    }
    return head;
}

int main()
{
    int a[] = {1, 2, 2, 3, 3, 3, 4, };
    ListNode* head = generateList(a, sizeof(a) / sizeof(int));
    printList(head);

    head = deleteDuplicates(head);
    printList(head);
    return 0;
}

