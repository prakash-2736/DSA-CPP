class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        // for (int i = 0; i < nums.size(); i++) {

        //     int maxi = *max_element(nums.begin(), nums.begin() + i);
        //     int mini = *min_element(nums.begin() + i, nums.end());
        //     if (maxi - mini <= k) {
        //         return i;
        //     }
        // }

        // return -1;

        int n = nums.size();
        if (n == 0)
            return -1;
        vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }
        int maxi = nums[0];

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            int mini = suffMin[i];

            if (maxi - mini <= k) {
                return i;
            }
        }

        return -1;
    }
};
