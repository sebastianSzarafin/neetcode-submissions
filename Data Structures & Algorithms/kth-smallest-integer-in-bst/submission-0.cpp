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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr || !s.empty()) {
            // Reach leftmost node
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            // Process node
            curr = s.top();
            s.pop();

            k--;
            if (k == 0) { return curr->val; }

            // Move right
            curr = curr->right;
        }

        return INT_MIN;
    }
};
