class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch) {

        // Row Check ANd Col Check
        for (int i = 0; i < 9; i++) {
            // chcek row
            if (i != col && board[row][i] == ch)
                return false;

            // Check column 
            if (i != row && board[i][col] == ch)
                return false;
        }

        // 3x3 Box Check
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (i == row && j == col)
                    continue;

                if (board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!isSafe(board, i, j, board[i][j])) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
