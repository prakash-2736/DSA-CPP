#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {      // bruute force  Time Complexity: O(N2)  Space Complexity: O(1) 
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};



  // unordered_map<int, int> mpp;
  //   for (int i = 0; i < n; i++) {
  //       int num = arr[i];
  //       int moreNeeded = target - num;
  //       if (mpp.find(moreNeeded) != mpp.end()) {     better -- TC :O{nlogn)   sc:O{n}
  //           return {mpp[moreNeeded], i};
  //       }
  //       mpp[num] = i;
  //   }
  //   return { -1, -1};



  // sort(arr.begin(), arr.end());
  //   int left = 0, right = n - 1;
  //   while (left < right) {
  //       int sum = arr[left] + arr[right];
  //       if (sum == target) {
  //           return "YES";
  //       }                               optimal ---- two pointer tc = O(nlogn)   sc:O(1);
  //       else if (sum < target) left++;
  //       else right--;
  //   }
  //   return "NO";

}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}
