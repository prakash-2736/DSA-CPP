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
    int minDepth(TreeNode* root) {

        // if (root == NULL)
        //     return 0;

        // if (root->left == NULL && root->right == NULL)
        //     return 1;

        // if (root->left == NULL)
        //     return 1 + minDepth(root->right);

        // if (root->right == NULL)
        //     return 1 + minDepth(root->left);

        // return 1 + min(minDepth(root->left), minDepth(root->right));

        if (root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left == NULL && front->right == NULL)
                    return depth;
                if (front->left != NULL)
                    q.push(front->left);
                if (front->right != NULL)
                    q.push(front->right);
                n--;
            }
            depth++;
        }
        return depth;
    }
};
