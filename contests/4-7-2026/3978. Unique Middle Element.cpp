class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        // vector<int> freq;
        int n = nums.size();
        int mid = nums[n / 2];
        int c = 0;
        // for(int x: nums){
        //     freq[x]++;
        // }

        // if(freq[nums[n/2]] > 1){
        //     return false;
        // }

        for (int x : nums) {
            if (x == mid) {
                c++;
                if (c > 1)
                    return false;
            }
        }

        return c == 1;
    }
};
