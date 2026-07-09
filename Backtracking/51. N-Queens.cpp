class Solution {
public:
    bool is_safe(vector<int>& board, int row, int col) {
        for (int i = 0; i < row; i++) {

            if (board[i] == col || abs(i - row) == abs(board[i] - col)) {
                return false;
            }
        }

        return true;
    }
    void solve(int n, int row, vector<int>& board,
               vector<vector<string>>& ans) {

        if (row == n) {
            vector<string> current_sol;
            
            for (int i = 0; i < n; i++) {
                string s(n, '.');
                s[board[i]] = 'Q';
                current_sol.push_back(s);
            }
            ans.push_back(current_sol);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (is_safe(board, row, i)) {
                board[row] = i;

                solve(n, row + 1, board, ans);

                board[row] = -1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> board(n, -1);
        vector<vector<string>> ans;
        solve(n, 0, board, ans);

        return ans;
    }
};
