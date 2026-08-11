class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            } else {
                break;
            }
        }

        unordered_set<int> uniqueNums(nums.begin(), nums.end());

        while (uniqueNums.count(prefixSum)) {
            prefixSum++;
        }

        return prefixSum;
    }
};
