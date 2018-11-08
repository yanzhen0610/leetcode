/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *p = head, *q = head->next, *tmp, *l = nullptr;
        
        while ((tmp = q->next) && (q = tmp->next))
        {
            tmp = p->next;
            p->next = l;
            l = p;
            p = tmp;
        }
        
        if (q) q = p->next; // even
        else q = p->next->next; // odd
        p->next = l;
        
        while (q)
        {
            if ((q->val) != (p->val)) return false;
            q = q->next;
            p = p->next;
        }
        
        return true;
    }
};