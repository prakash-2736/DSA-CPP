class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if(nums.empty()) return 0;

        // sort(nums.begin(), nums.end());

        // int c = 1;
        // int l = 1;

        // for(int i = 0; i < nums.size() - 1; i++) {
        //     if(nums[i+1] == nums[i]) {
        //         continue;   // skip duplicate
        //     }
        //     else if(nums[i+1] == nums[i] + 1) {
        //         c++;
        //     }
        //     else {
        //         c = 1;                  // tc:O(nlogn) + O(n)     sc : O(1) 
        //     }

        //     l = max(l, c);
        // }

        // return l;

      set<int> st;
        for (int num : nums)
            st.insert(num);

        int l = 0;

        for (int num : st) {

            if (!st.count(num-1)){
                int curr = num ;
                int c= 1;

                while(st.count(curr+1)){
                    curr++;                //tc O(n) + O(2n)    sc:O(n)
                    c++;
                }

                l = max(l,c);
            }
        }

        return l ;
    }
};
