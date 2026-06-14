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
    int pairSum(ListNode* head) {

        // vector<int> v;

        // while (head) {
        //     v.push_back(head->val);
        //     head = head->next;
        // }

        // int ans = 0;
        // int n = v.size();

        // for (int i = 0; i < n / 2; i++) {
        //     ans = max(ans, v[i] + v[n - 1 - i]);
        // }

        // return ans;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        int ans = 0;
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};
