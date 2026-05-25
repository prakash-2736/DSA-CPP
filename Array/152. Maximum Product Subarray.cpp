class Solution {
public:
    int maxProduct(vector<int>& nums) {
          int n = nums.size();

        int pre = 1, suff = 1;

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (pre == 0) pre = 1;

            if (suff == 0) suff = 1;

            pre *= nums[i];

            suff *= nums[n - i - 1];

            ans = max(ans, max(pre, suff));
        }

        // Return the final answer
        return ans;




        // int currMax = nums[0];
        // int currMin = nums[0];
        // int ans = nums[0];

        // for(int i = 1; i < nums.size(); i++) {
        //     if(nums[i] < 0)                                   // for overflow 
        //         swap(currMax, currMin);

        //     currMax = max(nums[i], currMax * nums[i]);
        //     currMin = min(nums[i], currMin * nums[i]);

        //     ans = max(ans, currMax);
        // }

        // return ans;
    }
};
