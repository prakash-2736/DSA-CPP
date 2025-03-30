#include <bits/stdc++.h>
using namespace std;
void left_rotate_by_1_place(int arr[], int n){
    int temp = arr[0];
    for (int i = 1; i <= n-1; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;



  
}

void left_rotate_by_k_places(int arr[], int n, int k){
    int temp[k];
    for(int i = 0; i <= k-1; i++){
        temp[i] = arr[i];
    }
    for(int i = k; i<= n-1; i++){   // brute force   Time Complexity: O(n+k)   Space Complexity: O(k)
        arr[i-k] = arr[i];
    }
    for(int i = n-k; i <= n-1; i++){
        arr[i] = temp[i-(n-k)];
    }

    // reverse(arr, arr+k);
    // reverse(arr+k, arr+n);    // optimal TC : O(2n)   The space Complexity is O(1)
    // reverse(arr, arr+n);


  
}
int main() {
    int n,k;
    cin >> n // >> k;
    //k = k%n ;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
  
    left_rotate_by_1_place(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    left_rotate_by_k_places(arr, n, k);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
