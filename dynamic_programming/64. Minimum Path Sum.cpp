class Solution {
public:
    // int solve(vector<vector<int>>& grid, int i, int j,
    //           vector<vector<int>>& dp) {

    //     if (i == 0 && j == 0) {
    //         return grid[0][0];
    //     }

    //     if (i < 0 || j < 0) {
    //         return INT_MAX;
    //     }

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int up = solve(grid, i - 1, j, dp);
    //     int left = solve(grid, i, j - 1, dp);

    //     int min_prev = min(up, left);
    //     return dp[i][j] = grid[i][j] + min_prev;
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // return solve(grid, n - 1, m - 1, dp);

        vector<vector<int>> dp(n, vector<int>(m, 0));

        dp[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                } else {
                    int up = INT_MAX;
                    int left = INT_MAX;

                    if (i > 0)
                        up = grid[i][j] + dp[i - 1][j];

                    if (j > 0)
                        left = grid[i][j] + dp[i][j - 1];

                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
