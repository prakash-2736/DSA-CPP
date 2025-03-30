#include <bits/stdc++.h>
using namespace std;
int second_largest_element(int arr[], int n){
    sort(arr, arr+n);
    int second_largest;
    for(int i = n-2; i >= 0; i--){
        if (arr[i] != arr[n-1]){       // bruteforce ---- Time Complexity: O(n log n) + O(n)     Space Complexity: O(N) + O(1
            second_largest = arr[i];
            return second_largest;
        }
    }
    return 0;



   // int max = arr[0];
   //  for(int i = 0; i < n; i++)
   //      if(max < arr[i])
   //          max = arr[i];
   //  int second_largest = -1;
   //  for (int i = 0; i <= n-1; i++){
   //      if(arr[i] > second_largest && arr[i] != max){        // optimal 1 -----Time Complexity = 2N Steps = O(2N)   Space Complexity = O(1) 
   //          second_largest = arr[i];
   //      }
   //  }
   //  return second_largest;





  // int max = arr[0];
  //   int second_largest = -1;
  //   for (int i = 1; i <= n-1; i++){
  //       if (arr[i] > max){
  //           second_largest = max;                     // optimal 2 -----Time Complexity = N Steps = O(2N)   Space Complexity = O(1)
  //           max = arr[i];
  //       }
  //       if (arr[i] > second_largest && arr[i] < max){
  //           second_largest = arr[i];
  //       }
  //   }
  //   return second_largest;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << second_largest_element(arr, n);
    return 0;
}
