#include <bits/stdc++.h>
using namespace std;
void largest_element(int arr[], int n){
    sort(arr, arr+n);
    cout << arr[n-1];//brtueforce ----- TC:O(nlogn) ,SC:O(1)  


  // int max = arr[0];
  //   for(int i = 0; i < n; i++)
  //       if(max < arr[i])       // optimal   ---- TC : O(n)  , SC: O(1) 
  //           max = arr[i];
  //   cout << max;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    largest_element(arr, n);
    return 0;
}
