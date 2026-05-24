class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row_delta = {0, 1, 0, -1};
        vector<int> col_delta = {1, 0, -1, 0};
        int pos = 0;
        int row = 0;
        int col = 0;

        while (ans.size() != m * n) {
            ans.push_back(matrix[row][col]);
            matrix[row][col] = 10000;
            int next_row = row + row_delta[pos];
            int next_col = col + col_delta[pos];
            if (next_row >= m || next_row < 0 || next_col >= n ||
                next_col < 0 || matrix[next_row][next_col] == 10000) {
                pos = (pos + 1) % 4;
            }
            row += row_delta[pos];
            col += col_delta[pos];
        }
        return ans;



 //         int top = 0;
 //        int bottom = matrix.size() - 1;
 //        int left = 0;
 //        int right = matrix[0].size() - 1;
 //        vector<int> arr;
 //        while (top <= bottom && left <= right) {

 //            for (int i = left; i <= right; i++) {
 //                arr.push_back(matrix[top][i]);
 //            }
 //            top++;

 //            for (int i = top; i <= bottom; i++) {
 //                arr.push_back(matrix[i][right]);
 //            }
 //            right--;                                                                              //tc:O(m*n)   sc: O(n*m)

 //            if (top <= bottom) {
 //                for (int i = right; i >= left; i--) {
 //                    arr.push_back(matrix[bottom][i]);
 //                }
 //                bottom--;
 //            }

 //            if (left <= right) {
 //                for (int i = bottom; i >= top; i--) {
 //                    arr.push_back(matrix[i][left]);
 //                }
 //                left++;
 //            }
 //        }
 //        return arr;  


      
    }
};
