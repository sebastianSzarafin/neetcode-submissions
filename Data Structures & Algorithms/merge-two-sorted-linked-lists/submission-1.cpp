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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode p1(0);
        ListNode* p2 = &p1;
        while (list1 && list2) {
                if (list1->val < list2->val) {
                        p2->next = list1;
                        list1 = list1->next;
                }
                else {
                        p2->next = list2;
                        list2 = list2->next;
                }
                p2 = p2->next;
        }

        if (list1) {
                p2->next = list1;
        }
        else {
                p2->next = list2;
        }

        return p1.next;
    }
};
