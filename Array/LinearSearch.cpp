#include <bits/stdc++.h>
using namespace std;
int linear_search(int arr[], int n, int k){
    for(int i = 0; i < n; i++){
        if(arr[i] == k) return i;
    }
    return -1;
}
int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << linear_search(arr, n, k);
    return 0;
}
