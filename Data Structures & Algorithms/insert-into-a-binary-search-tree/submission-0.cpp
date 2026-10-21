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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        TreeNode* node = root;
        while (node->left || node->right) {
            if (node->val < val) {
                if (node->right) {
                    node = node->right;
                }
                else {
                    break;
                }
            }
            else {
                if (node->left) {
                    node = node->left;
                }
                else {
                    break;
                }
            }
        }
        
        TreeNode* leaf = new TreeNode(val);
        if (node->val < val) {
            node->right = leaf;
        }
        else {
            node->left = leaf;
        }

        return root;
    }
};