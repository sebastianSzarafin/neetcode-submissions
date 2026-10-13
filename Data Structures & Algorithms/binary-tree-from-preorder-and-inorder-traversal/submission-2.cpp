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
    TreeNode* build(const std::vector<int>& preorder, const int l, const int r) {
        if (l > r) {
            return nullptr;
        }

        const int val = preorder[m_idx++];
        const int mid = m_index_map.at(val);

        auto node = new TreeNode(val);
        node->left = build(preorder, l, mid - 1);
        node->right = build(preorder, mid + 1, r);

        return node;
    }

    std::unordered_map<int, int> m_index_map{};
    int m_idx = 0;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const std::size_t n = inorder.size();
        
        for (std::size_t i = 0; i < n; ++i) {
            m_index_map.emplace(inorder[i], i);
        }

        return build(preorder, 0, n - 1);
    }
};
