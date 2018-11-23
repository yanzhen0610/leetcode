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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        queue<ListNode*> q;
        ListNode *root, *c, *l1, *l2;
        for (auto list : lists)
            q.push(list);
        while (q.size() >= 2)
        {
            l1 = q.front();
            q.pop();
            l2 = q.front();
            q.pop();
            if (l1 and l2)
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
                q.push(l1);
                continue;
            }
            else if (l2)
            {
                q.push(l2);
                continue;
            }
            else
            {
                continue;
            }
            c = root;
            while (l1 and l2)
            {
                if (l1->val < l2->val)
                {
                    c->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    c->next = l2;
                    l2 = l2->next;
                }
                c = c->next;
            }
            if (l1)
            {
                c->next = l1;
            }
            else if (l2)
            {
                c->next = l2;
            }
            q.push(root);
        }
        if (q.empty()) return nullptr;
        return q.front();
    }
};