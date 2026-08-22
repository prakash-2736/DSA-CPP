class Solution {
public:
    // int fib(int n, vector<int>& dp) {
    //     if (n == 1)
    //         return 1;
    //     if (n == 2)
    //         return 2;
    //     if (dp[n] != -1) {

    //         return dp[n];
    //     }
    //     dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    //     return dp[n];
    // }
    int climbStairs(int n) {
        // if (n == 1)
        //     return 1;
        // if (n == 2)
        //     return 2;

        // vector<int> dp(n + 1, -1);
        // int a = fib(n, dp);

        // return a;

        vector<int> dp(n + 1, -1);

        dp[0] = 1;
        dp[1] = 1;

        //tabulation 

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
