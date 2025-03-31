#include <bits/stdc++.h>
using namespace std;
int findMissing(int arr[], int n) {
    for (int i = 1; i <= n; ++i) {
        int present = 0;
        for (int j = 0; j < n - 1; ++j) {
            if (i == arr[j]) {           // brute force    Time complexity: O(n^2), Space Complexity: O(1)
                present = 1;
                break;
            }
        }
        if (present == 0) {
            return i;
        }
    }
    return -1;



   // int hash[N + 1] = {0}; 
   //  for (int i = 0; i < N - 1; i++)
   //      hash[a[i]]++;
   //  for (int i = 1; i <= N; i++) {      // better ---- tc : O(2n)   Sc : O(n)
   //      if (hash[i] == 0) {
   //          return i;
   //      }
   //  }
   //  return -1;




  // int sum1 = 0;
  //   for (int i = 0; i < n - 1; i++) {
  //       sum1 += arr[i];
  //   }                                     // opptimal 1 ---- Time Complexity : O(N)   Space Complexity : O(1)
  //   int sum2 = (n * (n + 1)) / 2;
  //   return sum2 - sum1;



   // int xor1 = 0;
   //  int xor2 = 0;
   //  for (int i = 0; i < n-1; i++){
   //      xor1 = xor1^arr[i];         // opptimal 2 ---- Time Complexity : O(N)   Space Complexity : O(1)
   //      xor2 = xor2^(i+1);
   //  }
   //  return xor1 ^ xor2 ^ n;
}
int main() {
    int n;
    cin >> n;
    int arr[n-1];
    for (int i = 0; i < n-1; i++){
        cin >> arr[i];
    }
    cout << findMissing(arr, n);
    return 0;
}
