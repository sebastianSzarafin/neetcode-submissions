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
        if (!head) {
            return nullptr;
        }
        
        Node* p1 = new Node(head->val);
        Node* mem = p1;

        Node* p2 = head->next;
        while (p2) {
            p1->next = new Node(p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }

        std::unordered_map<Node*, Node*> r_map{};
        r_map.emplace(std::pair{nullptr, nullptr});

        p1 = mem;
        p2 = head;

        while (p1) {
            r_map.emplace(std::pair{p2, p1});
            p1 = p1->next;
            p2 = p2->next;
        }

        p1 = mem;
        p2 = head;

        while (p1) {
            p1->random = r_map.at(p2->random);
            p1 = p1->next;
            p2 = p2->next;
        }

        return mem;
    }
};
