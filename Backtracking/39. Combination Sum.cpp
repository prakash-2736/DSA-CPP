class Solution {
public:
    void solve(int index, int k , vector<int> & nums ,  vector<int>& temp,
               vector<vector<int>>& ans) {
        int a = accumulate(temp.begin(), temp.end(), 0);
        if(a > k){
            return ;
        }
        if (a == k) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            temp.push_back(nums[i]);

            solve(i, k, nums,  temp, ans);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, k, nums , temp, ans);

        return ans;
    }
};
