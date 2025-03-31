#include <bits/stdc++.h>
using namespace std;
int singleElement(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (arr[i] == arr[j])       // brute force -----Time Complexity : ((n-1)x(n-1)) = O(n^2)   Space Complexity : O(1)
                count++;
        if (count == 1)
            return arr[i];
    }
    return -1; 


   // int n = arr.size();

   //  int maxi = arr[0];
   //  for (int i = 0; i < n; i++) {
   //      maxi = max(maxi, arr[i]);
   //  }
   //  vector<int> hash(maxi + 1, 0);
   //  for (int i = 0; i < n; i++) {     better --- Time Complexity: O(N)+O(N)+O(N)  Space Complexity: O(maxElement+1) 
   //      hash[arr[i]]++;
   //  }
   //  for (int i = 0; i < n; i++) {
   //      if (hash[arr[i]] == 1)
   //          return arr[i];
   //  }
   //  return -1;




   // map<int, int> m;
   //  for (int i = 0; i < n; i++) {
   //      m[arr[i]]++;
   //  }
   //  for (auto k : m) {                   better 2  --- Time Complexity: O(n * log(n)) Space Complexity is O(n/2) 
   //      if (k.second == 1) {
   //          return k.first;
   //      }
   //  }
   //  return -1;



//    int xor1 = 0;
//     for(int i = 0; i < n; i++)        // optimal  Time Complexity : O(n)  Space Complexity : O(1)
//         xor1 = xor1 ^ arr[i];
//     return xor1;
// }
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << singleElement(arr, n);
    return 0;
}
