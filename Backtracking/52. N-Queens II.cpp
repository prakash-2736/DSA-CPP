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
    void solve(int n, int row, vector<int>& board, int& c) {

        if (row == n) {
            c++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (is_safe(board, row, i)) {
                board[row] = i;

                solve(n, row + 1, board, c);

                board[row] = -1;
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> board(n, -1);
        int c = 0 ;
        solve(n, 0, board, c);

        return c;
    }
};
