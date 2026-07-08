class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int sum1 = 0;
        int sum2 = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int x : nums) {

            sum1 += x;
            maxi = max(maxi, sum1);
            if (sum1 < 0) {
                sum1 = 0;
            }

            sum2 = min(x, sum2 + x);
            mini = min(mini, sum2);
        }
        if (maxi < 0) {
            return maxi;
        }

        return max(maxi, total_sum - mini);
    }
};
