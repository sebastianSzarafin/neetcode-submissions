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
    void dfs(TreeNode** node_ptr, TreeNode* parent, int target) {

        const auto node = *node_ptr;

        if (!node) {
            return;
        }
        
        dfs(&node->left, node, target);
        dfs(&node->right, node, target);

        if (!node->left && !node->right && node->val == target) {
            if (parent && parent->left == node) {
                parent->left = nullptr;
            }
            else if (parent && parent->right == node) {
                parent->right = nullptr;
            }
            delete node;
            *node_ptr = nullptr;
        }
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(&root, nullptr, target);
        return root;
    }
};