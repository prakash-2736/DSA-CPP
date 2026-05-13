#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    int countSubarraysWithBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int count = 0;
        int lastInvalid = -1;

        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[i] > right) {
                lastInvalid = i;
                count = 0;
            }
            else if(nums[i] >= left && nums[i] <= right) {
                count = i - lastInvalid;
            }

            ans += count;
        }

        return ans;
    }
};
