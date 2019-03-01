/*
ID: code_lite
PROG: CARDMGK
LANG: C++                  
*/

#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    long long T;
    cin>>T;
    while(T--)
    {
      long long N;
      cin>>N;
      long long A[N];
      for(long long i=0;i<N;i++)
      {
        cin>>A[i];
      }
      long long B[N];
      long long neg_count=0;
      for(long long i=0;i<N-1;i++)
      {
        B[i] = A[i+1] - A[i];
        if(B[i]<0)
        {
          neg_count++;
        }
      }
      if(neg_count == 0)
      {
        cout<<"YES\n";
      }
      else if(neg_count>1)
      {
        cout<<"NO\n";
      }
      else
      {
          if(A[N-1]<=A[0])
          {
            cout<<"YES\n";
          }
          else
          {
            cout<<"NO\n";
          }
      }
    }
    return 0;
} 