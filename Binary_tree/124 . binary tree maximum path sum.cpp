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
private:
    int calculateMaxGain(TreeNode* node, int& max_sum) {
        if (node == nullptr) {
            return 0;
        }

        int leftGain = max(0, calculateMaxGain(node->left, max_sum));
        int rightGain = max(0, calculateMaxGain(node->right, max_sum));

        int currentPathSum = node->val + leftGain + rightGain;

        max_sum = max(max_sum, currentPathSum);

        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        calculateMaxGain(root, max_sum);
        return max_sum;
    }
};