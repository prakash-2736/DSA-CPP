#include<bits/stdc++.h>
using namespace std;
int remove_duplicates(int a[], int n)
{
    set<int> s;
    for(int i=0;i<=n-1;i++)
    {
        s.insert(a[i]);
    }
    int j=0;
    for(auto k: s)          // brute force  -------Time Complexity : O(NlogN + N)    Space Complexity : O(N)
 
    {
        a[j]=k;
        j++;
    }
    return s.size();


  // int i = 0;
  //   for(int j=1;j<=n-1;j++)
  //   {
  //       if(a[i]!=a[j])
  //       {
  //           a[i+1]=a[j];        // optimal Time Complexity : O(n)   Space Complexity : O(1)
  //           i++;
  //       }
  //   }
  //   return (i+1);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<remove_duplicates(a,n)<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
