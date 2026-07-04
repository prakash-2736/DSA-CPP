class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        int maxl = nums[0];
        int ans = 0;

        for (int j = k; j < n; j++) {
            maxl = max(maxl, nums[j - k]);
            ans = max(ans, maxl + nums[j]);
        }
        return ans;
    }
};
