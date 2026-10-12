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
    void dfs(int& good_nodes, const TreeNode* node, int current_max) {
        if (!node) {
            return;
        }

        if (node->val >= current_max) {
            good_nodes++;
        }

        current_max = std::max(current_max, node->val);

        dfs(good_nodes, node->left, current_max);
        dfs(good_nodes, node->right, current_max);
    }

public:
    int goodNodes(TreeNode* root) {
        int good_nodes = 0;
        dfs(good_nodes, root, root->val);
        return good_nodes;
    }
};
