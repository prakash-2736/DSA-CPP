/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<vector<int>> arr(m,vector<int>(n,-1));

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (head != nullptr) {

            // Left to Right
            for (int i = left; i <= right && head != nullptr; i++) {
                arr[top][i] = head->val;
                head = head->next;
            }
            top++;

            // Top to Bottom
            for (int i = top; i <= bottom && head != nullptr; i++) {
                arr[i][right] = head->val;
                head = head->next;
            }
            right--;

            //  Right to Left
            for (int i = right; i >= left && head != nullptr; i--) {
                arr[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;

            // Bottom to Top
            for (int i = bottom; i >= top && head != nullptr; i--) {
                arr[i][left] = head->val;
                head = head->next;
            }
            left++;
        }

        return arr;
    }
      
};
