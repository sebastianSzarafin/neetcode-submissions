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
    bool isBalanced(TreeNode* root) {
        if (!root) { return true; }
        return std::abs(subtreeSize(root->left) - subtreeSize(root->right)) <= 1
            && isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int subtreeSize(TreeNode* root) {
        if (subtreeSizeCache.contains(root)) { return subtreeSizeCache.at(root); }
        if (!root) { return 0; }
        const int size = std::max(subtreeSize(root->left), subtreeSize(root->right)) + 1;
        subtreeSizeCache.emplace(root, size);
        return size;
    }

    std::map<TreeNode*, int> subtreeSizeCache;
};
