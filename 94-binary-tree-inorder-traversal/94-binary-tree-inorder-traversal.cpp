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
    void inorderHelper(TreeNode* root, vector<int>& res) {
        if (root == nullptr)
            return;
        inorderHelper(root->left, res);
        res.push_back(root->val);
        inorderHelper(root->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        inorderHelper(root, res);
        return res;
    }
};