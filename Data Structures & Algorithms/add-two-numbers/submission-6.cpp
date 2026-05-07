/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* p = l3;

        int m = 0;
        while (l1 || l2) {
            int val = m; 
            if (l1) { val += l1->val; }
            if (l2) { val += l2->val; }

            p->val = val % 10;
            m = val / 10;

            if (l1) { l1 = l1->next; }
            if (l2) { l2 = l2->next; }
            
            if (l1 || l2) {
                p->next = new ListNode(); 
                p = p->next;            
            }
        }

        if (m > 0) {
            p->next = new ListNode(m); 
        }

        return l3;
    }
};
