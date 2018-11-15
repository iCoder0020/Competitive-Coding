/*
ID: code_lite
PROG: CHFAR
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main()
{
  int T;
  cin>>T;
  for(int t = 0; t<T; t++)
  {
    int N,K;
    cin>>N>>K;
    int A[N];
    int count = 0;
    for(int n = 0; n<N; n++)
    { 
      cin>>A[n];
      if(A[n] > 1)
      {
        count++;
      }
    }
    if(count > K)
    {
      cout<<"NO\n";
    }
    else
    {
      cout<<"YES\n";
    }
  }
}