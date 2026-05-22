#include <bits/stdc++.h>
using namespace std;

class solution{
public:
    vector<int> getDominants(vector<int>& arr) {
       vector<int> domi;
       int n = arr.size();
       int max = arr[n-1];
       domi.push_back(arr[n-1]);
       
       
       for(int i = n-2 ; i>=0 ; i--){
           
           if(arr[i] >= max){
               domi.push_back(arr[i]);
               max = arr[i];
           }
       }
       reverse(domi.begin() , domi.end());
       return domi;
    }
};
