class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int p = 1;
        int c = 0;
        int l = 0;
        if(k <= 1){
            return 0;
        }
        for (int i = 0; i < nums.size(); i++) {

            p *= nums[i];

            while (p >= k) {
                p /= nums[l];
                l++;
            }

            c += i - l + 1;
        }
        return c;
    }
};
