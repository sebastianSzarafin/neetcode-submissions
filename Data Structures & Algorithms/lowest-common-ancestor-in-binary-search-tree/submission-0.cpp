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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            int diff1 = p->val - root->val;
            int diff2 = q->val - root->val;
            if (diff1 < 0 && diff2 < 0) {
                root = root->left;
            }
            else if(diff1 > 0 && diff2 > 0) {
                root = root->right;
            }
            else {
                return root;
            }
        }
    }
};
