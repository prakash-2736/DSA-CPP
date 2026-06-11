class Solution {
public:
    bool isCapacity(vector<int>& nums, int capacity, int days) {

        int requiredDays = 1;
        int load = 0;

        for (int num : nums) {

            if (load + num <= capacity) {
                load += num;
            } else {
                requiredDays++;
                load = num;
            }
        }

        return requiredDays <= days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        int ans = h;

        while (l <= h) {
            int mid = (l + h) / 2;

            if (isCapacity(nums, mid, days)) {
                ans = mid;
                h = mid - 1;

            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
