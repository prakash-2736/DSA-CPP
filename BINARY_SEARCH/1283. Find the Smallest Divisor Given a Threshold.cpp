class Solution {
public:
    int solve(vector<int> nums, int div) {

        int total = 0;
        for (auto num : nums) {

            total += (num + div - 1 / div);
        }

        return total;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int l = 1;
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = maxi;
        if (nums.size() == t)
            return maxi;
        while (l <= maxi) {

            int mid = l + ((maxi - l) / 2);

            int sum = solve(nums, mid);

            if (sum <= t) {
                ans = mid;
                maxi = mid - 1;

            } else
                l = mid + 1;
        }

        return ans;
    }
};
