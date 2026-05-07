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

    bool isValidBSTInternal(TreeNode* root, int minBound, int maxBound) {
        if (!root) { return true; }
        if (root->val <= minBound) { return false; }
        if (root->val >= maxBound) { return false; }
        return isValidBSTInternal(root->left, minBound, root->val) && isValidBSTInternal(root->right, root->val, maxBound);
    }

    bool isValidBST(TreeNode* root) {
        if (!root) { return true; }

        std::stack<TreeNode*> s;
        TreeNode* curr = root;
        int prev = INT_MIN;

        while (curr || !s.empty()) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                // ---
                TreeNode* v = s.top();

                if (v->val <= prev) { return false; }
                prev = v->val;

                s.pop();
                // ---

                curr = v->right;
            }
        }

        return true;
    }
};
