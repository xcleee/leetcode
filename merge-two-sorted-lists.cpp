/*
 * leetcode Merge Two Sorted Lists
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "listnode.h"
using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    ListNode* head = NULL;
    ListNode* cur = head;

    while (l1 && l2)
    {
        int val;
        if (l1->val < l2->val)
        {
            val = l1->val;
            l1 = l1->next;
        }
        else
        {
            val = l2->val;
            l2 = l2->next;
        }

        if (!head)
        {
            head = new ListNode(val);
            cur = head;
        }
        else
        {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
    }

    while (l1)
    {
        cur->next = new ListNode(l1->val);
        l1 = l1->next;
        cur = cur->next;
    }

    while (l2)
    {
        cur->next = new ListNode(l2->val);
        l2 = l2->next;
        cur = cur->next;
    }

    return head;
}

int main()
{
    int a[] = {1,3,5,7,8};
    int len1 = sizeof(a) / sizeof(int);
    int b[] = {2,4,6,9,10,11,12};
    int len2 = sizeof(b) / sizeof(int);
    ListNode* l1 = generateList(a, len1);
    printList(l1);
    ListNode* l2 = generateList(b, len2);
    printList(l2);
    ListNode* l3 = mergeTwoLists(l1, l2);
    printList(l3);
    delList(l3);
    return 0;
}

