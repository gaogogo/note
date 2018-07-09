#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    if(head==NULL)
        return NULL;
    struct ListNode *p = head->next;
    struct ListNode *pre, *q, *temp;

    struct ListNode* result = head;
    result->next = NULL;

    while(p)
    {
        q = result;
        pre = result;
        temp = p->next;

        while(q && q->val < p->val)
        {
            pre = q;
            q = q->next;
        }

        if(pre == q)
        {
            p->next = pre;
            result = p;
        }
        else{
            pre->next = p;
            pre->next->next = q;
        }
        p = temp;
    }
    return result;
}
