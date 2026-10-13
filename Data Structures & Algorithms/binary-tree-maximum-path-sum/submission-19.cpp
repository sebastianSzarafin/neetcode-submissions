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
    static constexpr int MIN_NUM = -1e6;
    std::unordered_map<TreeNode*, std::pair<int, int>> m_path_cache{}; // {node, [max downward path, max path through this node]}

    void dfs(TreeNode* root) {

        if (!root || m_path_cache.contains(root)) {
            return;
        }

        if (!root->left && !root->right) {
            m_path_cache.emplace(root, std::pair{root->val, root->val});
            return;
        }

        dfs(root->left);
        dfs(root->right);

        const auto& [left_downward, left_through] = root->left ? m_path_cache.at(root->left) : std::pair{MIN_NUM, MIN_NUM};
        const auto& [right_downward, right_through] = root->right ? m_path_cache.at(root->right) : std::pair{MIN_NUM, MIN_NUM};

        const int max_downward = std::max({root->val, root->val + left_downward, root->val + right_downward});
        const int max_through = std::max({max_downward, left_downward + root->val + right_downward, left_through, right_through});

        m_path_cache.emplace(root, std::pair{max_downward, max_through});
    }


public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        const auto& [max_downward, max_through] = m_path_cache.at(root);
        return std::max(max_downward, max_through);
    }
};
