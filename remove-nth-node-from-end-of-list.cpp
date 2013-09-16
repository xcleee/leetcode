/*
 * leetcode Remove Nth Node From End of List
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "listnode.h"
using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (!head || n <= 0)
        return NULL;

    ListNode* pre = head;
    ListNode* cur = head;
    ListNode* before = head;

    while (n--)
        before = before->next;

    while (before)
    {
        pre = cur;
        cur = cur->next;
        before = before->next;
    }

    pre->next = cur->next;
    // if the head node is deleted, update head
    ListNode* rt = head == cur ? head->next : head;
    // delete the useless node
    delete cur;
    return rt;
}


int main()
{
    ListNode* head = NULL;
    ListNode* cur = NULL;
    for (int i = 1; i < 6; i++)
    {
        ListNode* p = new ListNode(i);
        if (!head)
        {
            head = p;
            cur = head;
        }
        else
        {

            cur->next = p;
            cur = cur->next;
        }
    }

    cout << size(head) << endl;
    printList(head);

    head = removeNthFromEnd(head, 5);
    cout << size(head) << endl;
    printList(head);

    head = removeNthFromEnd(head, 6);
    cout << size(head) << endl;
    printList(head);

    delList(head);
    return 0;
}
