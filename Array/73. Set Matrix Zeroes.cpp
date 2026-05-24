class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rows(matrix.size(), false);
        vector<bool> cols(matrix[0].size(), false);

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }                                                                   //tc:O(m*n)    , sc:O(m+n)
        for (int i = 0; i < matrix.size(); i++) {
           
                for (int j = 0; j < matrix[0].size(); j++) {
                     if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                     
                }
            }
        }




// int m = matrix.size();
//         int n = matrix[0].size();
//         int firstRow = -1;
//         int firstColumn = -1;
    
//         for (int j = 0; j < n; ++j) {
//             if (matrix[0][j] == 0) {
//                 firstRow = 0;
//             }
//         }
        
//         for (int i = 0; i < m; ++i) {
//             if (matrix[i][0] == 0) {
//                 firstColumn = 0;
//             }
//         }
        
//         for (int i = 1; i < m; ++i) {
//             for (int j = 1; j < n; ++j) {
//                 if (matrix[i][j] == 0) {
//                     matrix[i][0] = 0;
//                     matrix[0][j] = 0;
//                 }
//             }
//         }
        
//         for (int i = 1; i < m; ++i) {
//             for (int j = 1; j < n; ++j) {
//                 if (matrix[i][0] == 0 || matrix[0][j] == 0) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
                                                                                         //tc : O(m*N)    sc:O(1)
//         if (firstRow == 0) {
//             for (int j = 0; j < n; ++j) {
//                 matrix[0][j] = 0;
//             }
//         }
        
//         if (firstColumn == 0) {
//             for (int i = 0; i < m; ++i) {
//                 matrix[i][0] = 0;
//             }
//         }
      
    }
};
