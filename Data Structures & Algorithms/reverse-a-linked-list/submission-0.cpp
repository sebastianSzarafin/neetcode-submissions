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
    ListNode* reverseList(ListNode* head) {
        if(!head) {return nullptr; }
        ListNode* p1 = head;
        if (!p1->next) { return p1; }
        ListNode* p2 = head->next;
        p1->next = nullptr;
        if (!p2->next) {
            p2->next = p1;
            return p2;
        }
        while (ListNode* p3 = p2->next) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        p2->next = p1;
        return p2;
    }
};
