/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, TreeNode* target) {
        if (!root) {
            return true;
        }

        if (root->val != target->val) {
            return false;
        }

        return solve(root->left , target) && solve(root->right, target);
    }
    bool isUnivalTree(TreeNode* root) {
        if (!root) {
            return false;
        }

        return solve(root, root);
    }
};
