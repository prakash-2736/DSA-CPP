class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>>& dp) {

        if (i > m || j > n || i < 0 || j < 0) {
            return 0;
        }
        if (i == m && j == n) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int l = solve(m, n, i, j + 1, dp);
        int r = solve(m, n, i + 1, j, dp);

        return dp[i][j] = l + r;
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, 0, 0, dp);
    }
};
