/*
ID: code_lite
PROG: SPREAD2
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long T;
    cin>>(T);
    long long n;
    while(T--)
    {
      cin>>n;
      long long arr[n];
      long long prefix[n]={0};

      cin>>arr[0];
      prefix[0]=arr[0];
      for(long long i=1;i<n;i++)
      {
        cin>>arr[i];
        prefix[i] = prefix[i-1]+arr[i];
      }

      long long index=0,count=0;
      while(index<n-1)
      {
        count++;
        index += prefix[index];
      }      
    cout<<count<<"\n"; 
    }
    return 0;
}