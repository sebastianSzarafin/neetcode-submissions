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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* prev = nullptr;
        TreeNode* node = root;

        while (node && node->val != key) {
            prev = node;
            if (node->val < key) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }

        if (!node) {
            return root;
        }

        TreeNode* leaf = node;

        if (leaf->left) {
            prev = leaf;
            leaf = leaf->left;
            while (leaf->right) {
                prev = leaf;
                leaf = leaf->right; 
            }
        }
        else if (leaf->right) {
            prev = leaf;
            leaf = leaf->right;
            while (leaf->left) { 
                prev = leaf;
                leaf = leaf->left; 
            }
        }

        std::swap(node->val, leaf->val);
        
        if (prev) {
            if (prev->left == leaf) {
                prev->left = nullptr;
            }
            else {
                prev->right = nullptr;
            }
        }
        if (leaf == root) {
            root = nullptr;
        }
        delete leaf;

        return root;
    }
};