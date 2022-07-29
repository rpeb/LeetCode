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
    void preorderHelper(TreeNode* root, vector<int>& res) {
        if (root == nullptr)
            return;
        res.push_back(root->val);
        preorderHelper(root->left, res);
        preorderHelper(root->right, res);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        preorderHelper(root,res);
        return res;
    }
};