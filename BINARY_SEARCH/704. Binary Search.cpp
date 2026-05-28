class Solution {
public:
    int search(vector<int>& nums, int target) {
        long low = 0;
        long high = nums.size()-1;
        while (low <= high) {
            long mid = low +  (high -low ) / 2;
            if (nums[mid] == target)
                return mid;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
