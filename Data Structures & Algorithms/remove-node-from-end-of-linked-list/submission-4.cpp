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
        ListNode* node = head;
        int len = 0;

        while (node) {
            len++;
            node = node->next;
        }

        ListNode* prev = nullptr;
        len -= n;
        node = head;

        while (len > 0) {
            len--;
            prev = node;
            node = node->next;
        }

        if (!prev) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        else {
            ListNode* tmp = node;
            prev->next = node->next;
            delete tmp;
        }

        return head;
    }
};
