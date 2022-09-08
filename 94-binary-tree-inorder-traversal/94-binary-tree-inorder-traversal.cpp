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
    void inorderHelper(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        inorderHelper(root->left,v);
        v.push_back(root->val);
        inorderHelper(root->right,v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorderHelper(root,v);
        return v;
    }
};