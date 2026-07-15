class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nRow = r + dRow[d];
                int nCol = c + dCol[d];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    dist[nRow][nCol] == -1) {
                    dist[nRow][nCol] = dist[r][c] + 1;
                    q.push({nRow, nCol});
                }
            }
        }

        return dist;
    }
};
