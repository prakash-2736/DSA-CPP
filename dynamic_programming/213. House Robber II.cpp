class Solution {
public:
    int solve(vector<int>& arr, int l, int r) {
        if (arr.empty())
            return 0;

        int n = arr.size();
        if (n == 1)
            return arr[0];

        int prev2 = 0;
        int prev = 0;

        for (int i = l; i <= r; i++) {
            // Option 1: Pick the current house and add the value from prev2
            int include = arr[i];
            if (i > 1)
                include += prev2;
            // Option 2: Skip the current house, take prev

            int exclude = prev;

            int curr = max(include, exclude);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};
