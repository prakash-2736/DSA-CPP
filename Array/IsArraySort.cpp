#include<bits/stdc++.h>
using namespace std;

bool is_Sorted(int a[],int n)
{
    for(int i=0;i<=n-2;i++)
    {
        if( a[i] > a[i+1] )
            return false;
    }
    return true;
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
    cout<<is_Sorted(a,n)<<endl;
    return 0;
}
