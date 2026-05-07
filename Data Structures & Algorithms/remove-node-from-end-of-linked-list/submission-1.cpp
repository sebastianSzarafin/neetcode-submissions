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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        int count = 0;
        
        while (p1) {
            ++count;
            p1 = p1->next;    
        }

        count -= n;

        p1 = head;

        if (count == 0) {
            // First element
            head = head->next;
            delete p1;
        }
        else {
            while (count - 1 > 0) {
                p1 = p1->next;
                --count;
            }

            ListNode* p2 = p1->next;
            if (p2) { p1->next = p2->next; }
            delete p2;
        }

        return head;
    }
};
