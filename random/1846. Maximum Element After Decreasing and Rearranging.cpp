class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        if (arr[0] != 1) {
            arr[0] = 1;
        }
        int maxi = arr[0];
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) <= 1) {
                maxi = max(arr[i], maxi);
            } else {
                arr[i] = maxi + 1;
                maxi = max(arr[i], maxi);
            }
        }
        return maxi;
    }
};
