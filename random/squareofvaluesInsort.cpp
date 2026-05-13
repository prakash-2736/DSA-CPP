#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    vector<int> getSortedSquares(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int idx = n - 1;

        while(left <= right) {
            int l = arr[left] * arr[left];
            int r = arr[right] * arr[right];

            if(l > r) {
                ans[idx] = l;
                left++;
            } else {
                ans[idx] = r;
                right--;
            }
            idx--;
        }

        return ans;
    }
};
