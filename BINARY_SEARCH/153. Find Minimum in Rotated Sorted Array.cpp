class Solution {
public:
    int findMin(vector<int>& nums) {

        // for (int i = 0; i < nums.size() - 1; i++) {

        //     if (nums[i] > nums[i + 1]) {
        //         return nums[i + 1];
        //     }
        // }

        // return nums[0];

        int l = 0;
        int h = nums.size() - 1;
        int last = nums[h];
        while (l <= h) {

            int mid = (l + h) / 2;

            if (nums[mid] > last)
                l = mid + 1;
            else
                h = mid - 1;
        }

        return nums[l];
    }
};
