#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    vector<vector<int>> pascalsTriangle(int n) {
        if(n == 1) return {{1}};
        if(n == 2) return {{1}, {1,1}};
        vector<vector<int>> ans = {{1}, {1,1}};
        vector<int> prev = {1,1};
        for(int i=3; i<=n; i++){
            vector<int> cur(i);
            cur[0] = 1;
            cur[i-1] = 1;
            for(int j=1; j<i-1; j++){
                cur[j] = prev[j] + prev[j-1];
            }
            ans.push_back(cur);
            prev = cur;
        }
        return ans;

// vector<vector<int>> triangle;

//         for (int i = 0; i < numRows; ++i) {
//             vector<int> row(i + 1, 1);

//             for (int j = 1; j < i; ++j) {
//                 row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
//             }

//             triangle.push_back(row);
//         }

//         return triangle;

      
    }
};




class Solution {
public:
    vector<int> generateRow(int row) {

        long long ans = 1;
        vector<int> arr;
        arr.push_back(1);
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            arr.push_back(ans);
        }
        return arr;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        for (int i = 1; i <= numRows; i++) {

            arr.push_back(generateRow(i));
        }
        return arr;
    }
};
