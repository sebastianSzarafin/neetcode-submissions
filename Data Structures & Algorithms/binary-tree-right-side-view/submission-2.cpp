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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;

        if (!root) { return result; }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            while (n > 0) {
                TreeNode* v = q.front();
                if (n == 1) {
                    result.push_back(v->val);
                }
                if (v->left) { q.push(v->left); }
                if (v->right) { q.push(v->right); }
                n--;
                q.pop();
            }
        }

        return result;
    }
};
