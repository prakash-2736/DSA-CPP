class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int first = nums[i];
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int val = first + nums[j] + nums[k];
                if (val == 0) {
                    ans.push_back(vector<int>{first, nums[j], nums[k]});
                    j++;
                    k--;
                    while ( j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                } else if (val < 0) {
                    j++;
                } else if (val > 0) {
                    k--;
                }
            }
        }
        return ans;
    }
};
