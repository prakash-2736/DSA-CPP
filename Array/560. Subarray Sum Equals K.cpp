class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map ;
        map[0] = 1;
        int preFix = 0;
        int c= 0;
        for(int i =0 ; i < nums.size();i++){
            preFix += nums[i];
            int removal = preFix - k;
            c += map[removal];
            map[preFix] += 1;
        }
        return c;
     }
};
