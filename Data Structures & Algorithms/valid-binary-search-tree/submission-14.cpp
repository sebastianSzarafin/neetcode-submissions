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

 #include <ranges>

class Solution {
private:
    void dfs(std::vector<int>& q, const TreeNode* node) {
        if (!node) {
            return;
        }

        dfs(q, node->left);
        q.emplace_back(node->val);
        dfs(q, node->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        std::vector<int> q{};
        dfs(q, root);
        
        for (std::size_t i = 0; i < q.size() - 1; ++i) {
            if (q[i] >= q[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
