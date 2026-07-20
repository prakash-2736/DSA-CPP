class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;

        k = k % totalElements;

        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Convert 2D index (i, j) to 1D index
                int old1DIndex = i * n + j;

                // Calculate the new 1D index after shifting
                int new1DIndex = (old1DIndex + k) % totalElements;

                // Convert the new 1D index back to 2D indices
                int newRow = new1DIndex / n;
                int newCol = new1DIndex % n;

                result[newRow][newCol] = grid[i][j];
            }
        }

        return result;
    }
};
