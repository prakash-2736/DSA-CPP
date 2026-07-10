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
    // void traversal(TreeNode* root, vector<vector<int>>& res, int depth) {

    //     if (root == NULL) {
    //         return;
    //     }
    //     if (depth >= res.size()) {
    //         res.push_back(vector<int>());
    //     }

    //     res[depth].push_back(root->val);
    //     traversal(root->left, res, depth + 1);
    //     traversal(root->right, res, depth + 1);
    // }
    vector<vector<int>> levelOrder(TreeNode* root) {
        // vector<vector<int>> res;

        // traversal(root, res, 0);

        // return res;


        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int n = q.size(), iter = 0;
            for (int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
