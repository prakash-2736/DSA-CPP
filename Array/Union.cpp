#include <bits/stdc++.h>
using namespace std;
vector<int> get_union(vector<int> a, vector<int> b){
    vector<int> ans;
    set<int> s;
    for (auto k:a) s.insert(k);
    for (auto k:b) s.insert(k);         // brute force    Time Complexity = O((m+n)log(m+n))  Space Complexity = O(2(m + n))

    for(auto k:s) ans.push_back(k);
    return ans;





  // int i = 0, j = 0;
  //   vector<int> ans;
  //   while(i < a.size() && j < b.size()){
  //       if(a[i] <= b[j]){
  //           if(ans.empty() || a[i] != ans.back()){
  //               ans.push_back(a[i]);
  //           }
  //           i++;
  //       }
  //       else{
  //           if(ans.empty() || b[j] != ans.back()){             // optimal TC = O(m + n)  Space Complexity:  O(m + n)
  //               ans.push_back(b[j]);
  //           }
  //           j++;
  //       }
  //   }
  //   while(j < b.size()){
  //       if(ans.empty() || b[j] != ans.back()){
  //           ans.push_back(b[j]);
  //       }
  //       j++;
  //   }
  //   while(i < a.size()){
  //       if(ans.empty() || a[i] != ans.back()){
  //           ans.push_back(a[i]);
  //       }
  //       i++;
  //   }
  //   return ans;
}
int main() {
    int m,n;
    cin >> m >> n;
    vector<int> a;
    vector<int> b;

    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    vector<int> ans = get_union(a,b);
    for (auto k:ans) cout << k << " ";
    return 0;
}
