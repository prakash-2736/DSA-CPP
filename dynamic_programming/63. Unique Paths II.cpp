class Solution {
public:
    // int solve(vector<vector<int>>& arr, int m, int n, int i, int j,
    //           vector<vector<int>>& dp) {

    //     if (i > m || j > n || i < 0 || j < 0 || arr[i][j] == 1) {
    //         return 0;
    //     }
    //     if (i == m && j == n) {
    //         return 1;
    //     }

    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     int l = solve(arr, m, n, i, j + 1, dp);
    //     int r = solve(arr, m, n, i + 1, j, dp);

    //     return dp[i][j] = l + r;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));

        // return solve(arr, m - 1, n - 1, 0, 0, dp);

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0) {
                    dp[0][0] = 1;
                } else {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];

                    dp[i][j] = left + up;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
