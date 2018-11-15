/*
ID: code_lite
PROG: QUALPREL
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;

bool compareint(long long i1, long long i2) 
{ 
    return (i1 > i2); 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long T;
    cin>>T;
    long long n,k;
    while(T--)
    {
      cin>>n>>k;
      long long arr[n];
      for(long long i=0;i<n;i++)
      {
        cin>>arr[i];
      }
      sort(arr, arr+n,compareint);
      long long score = arr[k-1];
      long long index =k;
      long long count=0;
      while( index<n && arr[index]==score )
      {
        count++;
        index++;
      }
      cout<<count+k<<"\n";

    
    }
    return 0;
}