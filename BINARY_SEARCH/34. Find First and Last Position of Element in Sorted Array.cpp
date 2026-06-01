class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums,nums.size(), target);
        if(lb == nums.size() || nums[lb] != target ) return {-1,-1};
        int up = upperBound(nums,nums.size(),target);
        return {lb,up-1};

    }


int upperBound(vector<int> &nums, int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (nums[mid] > target) {
            ans = mid;
            
            high = mid - 1;
        }
        else {
            low = mid + 1; 
        }
    }
    return ans;
}
    int lowerBound(vector<int> &nums, int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (nums[mid] >= target) {
            ans = mid;
            
            high = mid - 1;
        }
        else {
            low = mid + 1; 
        }
    }
    return ans;
}
};
