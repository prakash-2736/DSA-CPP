class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int a = 0 ;
        // for(int i = 0 ; i < nums.size();i++){
        //     a ^= nums[i];
        // }
        // return a;




 int start = 0;
        int end = nums.size() - 1;
        while (start < end) {

            int mid = start + (end - start) / 2;
            int whichIndex = mid % 2 == 0 ? mid + 1 : mid - 1;
            if (nums[mid] == nums[whichIndex]) {
                start = mid + 1;
            } else
                end = mid;
        }
        return nums[start];
    }
};
