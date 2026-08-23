class Solution {
public:
    // int solve(vector<vector<int>>& arr, int i, int j ,vector<vector<int>>&
    // dp) {
    //     int n = arr.size();
    //     if (i == n - 1) {
    //         return arr[i][j];
    //     }

    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int l = arr[i][j] + solve(arr, i + 1, j, dp);
    //     int r = arr[i][j] + solve(arr, i + 1, j + 1, dp);

    //     return dp[i][j] = min(l, r);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        if (n == 1)
            return triangle[0][0];

        // vector<vector<int>> dp(n, vector<int>(n, -1));

        // return solve(triangle, 0, 0, dp);

        for (int i = n - 2; i >= 0; i--) {

            int m = triangle[i].size();

            for (int j = 0; j < m; j++) {

                int l = triangle[i + 1][j];
                int r = triangle[i + 1][j + 1];

                triangle[i][j] += min(l, r);
            }
        }

        return triangle[0][0];
    }
};
