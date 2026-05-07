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

        return isValidBSTInternal(root, -1000, 1000);
    }
};
