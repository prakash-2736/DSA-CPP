class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        long long sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        int left_sum = 0;
        vector<int> ans;
        int right_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            left_sum += nums[i];
            right_sum = sum - left_sum;
            ans.push_back(abs(right_sum - (left_sum - nums[i])));
        }
        return ans;



        //   int total = accumulate(nums.begin(), nums.end(), 0);

        // int left = 0;
        // vector<int> ans;

        // for(int i = 0; i < nums.size(); i++) {

        //     total -= nums[i]; 

        //     ans.push_back(abs(left - total));

        //     left += nums[i];
        // }

        // return ans;
    }
};
