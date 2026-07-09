class Solution {
public:
    void solve(int index, int k, vector<int>& nums, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            if (k < nums[i])
                break;
            temp.push_back(nums[i]);

            solve(i + 1, k - nums[i], nums, temp, ans);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, k, nums, temp, ans);

        return ans;
    }
};
