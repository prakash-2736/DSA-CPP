class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = INT_MIN;
        vector<int> pregcd(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            pregcd[i] = gcd(nums[i], mx);
        }
        sort(pregcd.begin(), pregcd.end());
        int l = 0;
        int h = nums.size() - 1;
        long long sum = 0;
        while (l < h) {
            sum += gcd(pregcd[l], pregcd[h]);
            l++;
            h--;
        }
        return sum;
    }
};
