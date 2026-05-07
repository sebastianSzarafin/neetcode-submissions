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
private:
    std::unordered_map<TreeNode*, int> cache;

public:
    int findMax(TreeNode* node) {
        if (!node) { return 0; }
        if (cache.contains(node)) { return cache.at(node); }
        
        int withNode = node->val;
        int withoutNode = 0;
        if (node->left) {
            withoutNode += findMax(node->left);
            if (node->left->left) {
                withNode += findMax(node->left->left);
            }
            if (node->left->right) {
                withNode += findMax(node->left->right);
            }
        }
        if (node->right) {
            withoutNode += findMax(node->right);
            if (node->right->left) {
                withNode += findMax(node->right->left);
            }
            if (node->right->right) {
                withNode += findMax(node->right->right);
            }
        }

        cache.emplace(node, std::max(withNode, withoutNode));
        
        return cache.at(node);
    }

    int rob(TreeNode* root) {
        cache.clear();
        return findMax(root);
    }
};