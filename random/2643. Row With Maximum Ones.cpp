class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
        int maxi = 0;
        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            int ones =
                arr[i].end() - lower_bound(arr[i].begin(), arr[i].end(), 1);
            if (ones > maxi) {
                maxi = ones;
                ans = i;
            }
        }

        return {ans,maxi};
    }
};
