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
    int max_sum = INT_MIN;

    int get_max_downward(TreeNode* root) {
        if (!root) { return 0; }

        int left_downward = std::max(0, get_max_downward(root->left));
        int right_downward = std::max(0, get_max_downward(root->right));

        int current_through = root->val + left_downward + right_downward;

        max_sum = std::max(max_sum, current_through);

        return root->val + std::max(left_downward, right_downward);
    }

public:
    int maxPathSum(TreeNode* root) {
        get_max_downward(root);
        return max_sum;
    }
};
