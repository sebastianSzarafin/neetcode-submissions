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
private:
    ListNode* reverseList(ListNode* head, ListNode* until = nullptr) {
        ListNode* prev = nullptr;
        while (head && head != until) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {

        /* Find middle node */

        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;

        while (fast) {
            fast = fast->next;
            count++;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
                count++;
            }
        }

        ListNode* mid = slow;

        /* Reverse the first half */

        ListNode* prev = reverseList(head, mid);

        /* Reorder */

        head = mid;
        ListNode* next = mid->next;
        bool swap = count % 2 == 0;

        while (prev && next) {
            if (swap) {
                mid->next = prev;
                prev = prev->next;
            }
            else {
                mid->next = next;
                next = next->next;
            }

            mid = mid->next;
            swap = !swap;
        }

        if (prev) {
            mid->next = prev;
        }

        if (next) {
            mid->next = next;
        }

        head = reverseList(head);
    }
};
