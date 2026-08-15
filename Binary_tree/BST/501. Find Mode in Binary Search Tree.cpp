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
    void inorder(TreeNode* root, vector<int>& modes, int& c, int& max_c,
                 TreeNode*& prev) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, modes, c, max_c, prev);
        if (prev != nullptr && prev->val == root->val) {
            c++;
        } else {
            c = 1;
        }
        if (c > max_c) {
            max_c = c;
            modes.clear();
            modes.push_back(root->val);
        } else if (c == max_c) {
            modes.push_back(root->val);
        }
        prev = root;
        inorder(root->right, modes, c, max_c, prev);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        int c = 0;
        int max_c = 0;
        TreeNode* prev = nullptr;
        inorder(root, modes, c, max_c, prev);
        return modes;
    }
};
