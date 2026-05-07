/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSame(TreeNode* root1, TreeNode* root2) {
        std::stack<TreeNode*> s1;
        std::stack<TreeNode*> s2;

        s1.push(root1);
        s2.push(root2);
        while (!s1.empty() && !s2.empty()) {
            TreeNode* v1 = s1.top();
            TreeNode* v2 = s2.top();
            if(v1->val != v2->val) { return false; }
            s1.pop();
            if (v1->left) { s1.push(v1->left); }
            if (v1->right) { s1.push(v1->right); }
            s2.pop();
            if (v2->left) { s2.push(v2->left); }
            if (v2->right) { s2.push(v2->right); }
        }

        return s1.empty() && s2.empty();
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()) {
            TreeNode* v = q.front();
            if (isSame(v, subRoot)) { return true; }
            if (v->left) { q.push_back(v->left); }
            if (v->right) { q.push_back(v->right); }
            q.pop_front();
        }
        return false;
    }
};
