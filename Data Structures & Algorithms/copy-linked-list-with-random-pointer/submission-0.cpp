/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) { return nullptr; }

        Node* new_head = new Node(head->val);
        Node* p1 = new_head;
        Node* p2 = head->next;

        while (p2) {
            p1->next = new Node(p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }

        std::unordered_map<Node*, Node*> hash_map;
        
        p1 = new_head;
        p2 = head;

        while (p2) {
            hash_map.emplace(p2, p1);
            p1 = p1->next;
            p2 = p2->next;
        }
        hash_map.emplace(nullptr, nullptr);

        p1 = new_head;
        p2 = head;

        while (p2) {
            p1->random = hash_map.at(p2->random);
            p1 = p1->next;
            p2 = p2->next;
        }

        return new_head;
    }
};
