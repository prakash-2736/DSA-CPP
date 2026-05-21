#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    int maxPairSum(vector<int>& arr, int n) {
        int maxi = INT_MIN;

        for(int i = 0; i < n - 1; i++) {
            maxi = max(maxi, arr[i] + arr[i + 1]);
        }

        return maxi;
    }
};
