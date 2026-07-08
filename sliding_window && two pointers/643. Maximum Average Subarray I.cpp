class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -DBL_MAX;
        int left = 0;
        double sum = 0;

        for (int r = 0; r < nums.size(); r++) {

            sum += nums[r];

            if (r - left + 1 == k) {
                ans = max(ans, sum / k);
                sum -= nums[left];
                left++;
            }
        }
        return ans;
    }
};
