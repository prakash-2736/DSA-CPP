class Solution {
public:
    int change(int T, vector<int>& arr) {
        if (T == 0) return 1;
        if (arr.empty()) return 0;

        vector<unsigned int> dp(T + 1, 0);
        
        dp[0] = 1;

        for (int coin : arr) {
            for (int target = coin; target <= T; target++) {
                dp[target] += dp[target - coin];
            }
        }

        return (int)dp[T];
    }
};
