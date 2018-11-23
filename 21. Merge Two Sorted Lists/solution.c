/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *root = NULL, *current = NULL;
    if (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            root = l1;
            l1 = l1->next;
        }
        else
        {
            root = l2;
            l2 = l2->next;
        }
    }
    else if (l1)
    {
        return l1;
    }
    else
    {
        return l2;
    }
    current = root;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    if (l1)
    {
        current->next = l1;
    }
    else
    {
        current->next = l2;
    }
    return root;
}