class Solution {
public:
    // bool solve(vector<int>& arr, int i, int target, vector<vector<int>>& dp)
    // {
    //     if (target == 0)
    //         return true;
    //     if (i == 0) {
    //         return target == arr[0];
    //     }

    //     if (dp[i][target] != -1) {
    //         return dp[i][target];
    //     }

    //     bool notTake = solve(arr, i - 1, target, dp);

    //     bool take = false;
    //     if (arr[i] <= target) {
    //         take = solve(arr, i - 1, target - arr[i], dp);
    //     }

    //     return dp[i][target] = take || notTake;
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total & 1)
            return false;

        int target = total / 2;

        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        // return solve(nums, n - 1, target, dp);

        // tablutaion

        // vector<bool> dp(target + 1, false);

        // dp[0] = true;

        // for (int i = 0; i < n; i++) {
        //     for (int j = target; j >= nums[i]; j--) {
        //         dp[j] = dp[j] || dp[j - nums[i]];
        //     }
        // }

        // return dp[target];

        bitset<10001> bits(1); 

        for (int num : nums) {
            bits |=
                (bits << num); 
        }

        return bits[target];
    }
};
