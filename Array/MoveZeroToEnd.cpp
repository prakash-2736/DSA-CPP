#include<bits/stdc++.h>
using namespace std;
void move_zeros(int a[],int n)
{
    vector<int> v;
    for(int i=0;i<=n-1;i++)
    {
        if(a[i]!=0)
        {
            v.push_back(a[i]);
        }
    }                          // bruteforce  Time Complexity : O(n)  Space Complexity : O(n)
    int j = 0;
    for(auto k: v)
    {
        a[j] = k;
        j++;
    }
    for(int i=v.size();i<=n-1;i++)
    {
        a[i]=0;
    }



  // int i = 0;
  //   for(int j=0;j<=n-1;j++)
  //   {
  //       if(a[j]!=0)
  //       {
  //           swap(a[i],a[j]);             // optimal  Time Complexity : O(n)  Space Complexity : O(1)
  //           i++;
  //       }
  //   }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<=n-1;i++)
    {
        cin>>a[i];
    }
    move_zeros(a,n);
    for(int i=0;i<=n-1;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
