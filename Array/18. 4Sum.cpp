class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
   // int n = arr.size();
   //      // Use set to avoid duplicate quadruplets
   //      set<vector<int>> st;

   //      for (int i = 0; i < n; i++) {
   //          for (int j = i + 1; j < n; j++) {
   //              for (int k = j + 1; k < n; k++) {
   //                  for (int l = k + 1; l < n; l++) {
   //                      long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
   //                      if (sum == target) {                                                              //tc:O(n^4)* logA   sc : 2O(a)
   //                          vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
   //                          sort(temp.begin(), temp.end());
   //                          st.insert(temp);
   //                      }
   //                  }
   //              }
   //          }
   //      }
   //      return vector<vector<int>>(st.begin(), st.end());

      

      // int n = arr.size();
      //   set<vector<int>> st;  

      //   // First loop - pick first number
      //   for (int i = 0; i < n; i++) {
      //       // Second loop - pick second number
      //       for (int j = i + 1; j < n; j++) {
      //           // HashSet to store numbers between j and k
      //           unordered_set<int> seen;

      //           // Third loop - pick third number
      //           for (int k = j + 1; k < n; k++) {
      //               long long required = (long long)target - arr[i] - arr[j] - arr[k];

      //               if (seen.count(required)) {
      //                   vector<int> temp = {arr[i], arr[j], arr[k], (int)required};
      //                   sort(temp.begin(), temp.end());                           //Time Complexity: O(N3*log(M))    Space Complexity: O(2 * no. of the quadruplets)+O(N), -- better
      //                   st.insert(temp);
      //               }

      //               seen.insert(arr[k]);
      //           }
      //       }
      //   }

      //   // Convert set into vector and return
      //   return vector<vector<int>>(st.begin(), st.end());




      
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int s = 0; s < n; s++) {
            if (s != 0 && nums[s] == nums[s - 1])
                continue;
            int first = nums[s];
            for (int i = s + 1; i < n; i++) {
                if (i != s + 1 && nums[i] == nums[i - 1])
                    continue;

                int j = i + 1;
                int k = n - 1;

                while (j < k) {
                    long val = (long)first + nums[j] + nums[k] + nums[i];
                    if (val == target) {
                        ans.push_back(
                            vector<int>{first, nums[i], nums[j], nums[k]});                      //tc:O(nlogn) + O(n^3)   sc:O(quadripltes )  --- optimal 
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1])
                            j++;
                        while (j < k && nums[k] == nums[k + 1])
                            k--;
                    } else if (val < target) {
                        j++;
                    } else if (val > target) {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
