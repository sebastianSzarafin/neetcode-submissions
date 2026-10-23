/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        
        std::unordered_set<Node*> visited{};
        std::unordered_map<Node*, Node*> copies{};
        std::queue<Node*> q{}; 

        q.push(node);
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();

            if (visited.contains(n)) {
                continue;
            }

            visited.emplace(n);
            copies[n] = new Node(n->val);
            for (auto neighbor : n->neighbors) {
                q.push(neighbor);
            }
        }

        visited.clear();
        q.push(node);
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();

            if (visited.contains(n)) {
                continue;
            }

            Node* c = copies[n];

            visited.emplace(n);
            for (auto neighbor : n->neighbors) {
                c->neighbors.emplace_back(copies[neighbor]);
                q.push(neighbor);
            }
        }

        return copies[node];
    }
};
