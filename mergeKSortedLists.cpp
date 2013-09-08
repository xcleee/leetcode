#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
using namespace std;

struct ListNode
{
    ListNode(int n, ListNode* p){
        val = n;
        next = p;
    }
    int val;
    ListNode* next;
};

ListNode* merge(ListNode* p, ListNode* q)
{
    if (p == NULL)
        return q;
    if (q == NULL)
        return p;

    ListNode* head = NULL;
    ListNode* curNode = NULL;

    while (p && q)
    {
        ListNode* node;
        if (p->val < q->val)
        {
            node = p;
            p = p->next;
        }
        else
        {
            node = q;
            q = q->next;
        }

        if (head == NULL)
            head = curNode = node;
        else
        {
            curNode->next = node;
            curNode = node;
        }
    }

    if (p)
        curNode->next = p;
    else if (q)
        curNode->next = q;

    return head;
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if (lists.size() < 1)
        return NULL;
    ListNode* head = lists[0];
    for (int i = 1; i < lists.size(); i++)
        head = merge(head, lists[i]);

    return head;
}

void printList(ListNode* head)
{
    ListNode* p = head;
    while (p != NULL)
    {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "null" << endl;
}

int main()
{
    int l1[] = {1, 3, 4, 6};
    int l2[] = {2, 5, 10, 12};
    int l3[] = {7, 8, 9, 11};
    int* l[] = {l1, l2, l3};
    int len[] = {sizeof(l1)/sizeof(int), sizeof(l1)/sizeof(int), sizeof(l1)/sizeof(int)};
    ListNode* h1 = NULL, *h2 = NULL, *h3 = NULL, *curNode = NULL;
    ListNode** h[] = {&h1, &h2, &h3};
    vector<ListNode*> lists;

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < len[j]; i++)
        {
            ListNode* p = new ListNode(l[j][i], NULL);
            if (*h[j] == NULL)
                *h[j] = curNode = p;
            else
            {
                curNode->next = p;
                curNode = p;
            }
        }
        lists.push_back(*h[j]);
    }
    printList(h1);
    printList(h2);
    printList(h3);

    cout << "-----------------After merge----------------" << endl;

    ListNode* head = mergeKLists(lists);
    printList(head);
    return 0;
}
