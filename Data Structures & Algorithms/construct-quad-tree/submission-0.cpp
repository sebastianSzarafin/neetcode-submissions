/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* dfs(const std::vector<std::vector<int>>& grid, const int r, const int c, const int n) {
        if (n == 1) {
            return new Node(grid[r][c], true);
        }

        const int half_n = n / 2;
        Node* tl = dfs(grid, r, c, half_n);
        Node* tr = dfs(grid, r, c + half_n, half_n);
        Node* bl = dfs(grid, r + half_n, c, half_n);
        Node* br = dfs(grid, r + half_n, c + half_n, half_n);

        Node* root;

        if (tl->val == tr->val && tr->val == bl->val && bl->val == br->val
            && tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
            root = new Node(tl->val, true);
            for (auto& n : { tl, tr, bl, br}) { delete n; }
        }
        else {
            root = new Node(false, false, tl, tr, bl, br);
        }

        return root;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size());
    }
};