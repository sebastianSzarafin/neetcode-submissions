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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;

        if (!root) { return result; }

        std::deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()) {
            std::size_t n = q.size();

            std::vector<int> l(n);
            for (std::size_t i = 0; i < n; ++i) {
                TreeNode* v = q.front();
                if (v->left) { q.push_back(v->left); }
                if (v->right) { q.push_back(v->right); }

                l[i] = v->val;
                q.pop_front();
            }
            result.emplace_back(l);
        }

        return result;
    }
};
