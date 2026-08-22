class Solution {
public:
    // memorization
    //  int solve(vector<int>& arr, int i, vector<int>& dp) {
    //      if (i < 0)
    //          return 0;
    //      if (i == 0)
    //          return arr[0];
    //      if (dp[i] != -1)
    //          return dp[i];

    //     int pick = arr[i] + solve(arr, i - 2, dp);
    //     int notPick = solve(arr, i - 1, dp);
    //     return dp[i] = max(pick, notPick);
    // }
    int rob(vector<int>& arr) {
        int n = arr.size();
        // vector<int> dp(n, -1);
        // return solve(arr, n - 1, dp);

        // tabluation
        // vector<int> dp(n, -1);
        // if (n == 1) {
        //     return arr[0];
        // }

        // dp[0] = arr[0];
        // dp[1] = max(arr[0], arr[1]);

        // for (int i = 2; i < n; i++) {

        //     dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        // }

        // return dp[n - 1];

        // space optimization

        if (arr.empty())
            return 0;

        int prev2 = 0;
        int prev = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            // Include current by adding it to two steps back
            int include = arr[i] + prev2;

            // Exclude current by taking previous best
            int exclude = prev;

            int curr = max(include, exclude);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
