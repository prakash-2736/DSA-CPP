class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> output(n,vector<int>(n,0));
        int col = matrix.size() -1;
        
         for(int i = 0 ; i< n ; i++){
            for(int j= 0 ;j < matrix[i].size() ; j++){
                output[j][col] = matrix[i][j];
            }
            col--;                                          // tc : O(n*m)  sc:O(n*m)

        }
         for(int i = 0 ; i< n; i++){
            for(int j= 0 ;j < matrix[i].size() ; j++){
               matrix[i][j] = output[i][j];
            }

        }




        // int n = matrix.size();

        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n ; j++) {
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }
                                           //optimal tc : O(n*m)  sc:O(1) 
        // for (auto& row : matrix) {
        //     reverse(row.begin(), row.end());
        // }
    }
};
