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
        std::stack<TreeNode*> s{};
        TreeNode* curr = root;

        // Iterative in-order DFS
        while (curr || !s.empty()) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                curr = s.top();
                s.pop();

                k--;
                if(!k) {
                    return curr->val;
                }

                curr = curr->right;
            }
        }
    }
};
