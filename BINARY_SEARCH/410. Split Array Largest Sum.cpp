class Solution {
public:
    bool IsLargest(vector<int>& nums, int mid, int k) {
        int c = 1;
        int total_sum = 0;

        for (int num : nums) {
            if (total_sum + num <= mid) {
                total_sum += num;
            } else {
                c++;
                total_sum = num;
            }
        }
        return c <= k;
    }
    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        int ans = h;

        while (l <= h) {

            int mid = l + ((h - l) / 2);

            if (IsLargest(nums, mid, k)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
