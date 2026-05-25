class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int m1 = 0;
        int m2 = 0;
        int n = nums.size();
        vector<int> ans;
        for (int num : nums) {

            if (m1 == 0 && num != l2) {
                m1 = 1;
                l1 = num;
            } else if (m2 == 0 && num != l1) {
                m2 = 1;
                l2 = num;
            } else if (l1 == num) {
                m1++;
            } else if (l2 == num) {
                m2++;
            } else {
                m1--;
                m2--;
            }
        }
        int c1 = 0, c2 = 0;

        for (int num : nums) {
            if (num == l1)
                c1++;
            if (num == l2)
                c2++;
        }

        if (c1 > n / 3)
            ans.push_back(l1);
        if (c2 > n / 3)
            ans.push_back(l2);

        return ans;
    }
};
