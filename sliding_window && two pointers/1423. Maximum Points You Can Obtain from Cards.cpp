class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int lsum = 0;
        int rsum = 0;
        int max_sum = 0;
        int n = arr.size() - 1;

        for (int i = 0; i < k; i++) {
            lsum += arr[i];
        }
        max_sum = lsum;

        for (int i = k - 1; i >= 0; i--) {

            lsum -= arr[i];
            rsum += arr[n];
            n--;
            max_sum = max(max_sum, lsum + rsum);
        }
        return max_sum;
    }
};
