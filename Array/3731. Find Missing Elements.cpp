class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> missing;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] > nums[i] + 1) {
                for (int j = nums[i] + 1; j < nums[i + 1]; ++j) {
                    missing.push_back(j);
                }
            }
        }
        
        return missing;
    }
};
