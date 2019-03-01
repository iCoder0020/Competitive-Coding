/*
ID: code_lite
PROG: ARRGRAPH
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{

    if(b == 0) {
            return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main()
{
    long long T;
    cin>>T;
    while(T--)
    {
      long long N;
      int count_47 = 0;
      cin>>N;
      long long A[N];
      for(long long i=0;i<N;i++)
      {
        cin>>A[i];
        if(A[i] == 47)
        {
          count_47++;
        }
      }
      if(N == 1)
      {
        cout<<"0\n";
        cout<<A[0]<<"\n";
      }
      else if(count_47 == N)
      {
        cout<<"1\n";
        cout<<"43 ";
        for(int i  = 1; i<N; i++)
        {
          cout<<A[i]<<" ";
        }
        cout<<"\n";
      }
      else
      {
        int gcd_1[N]={0};
        int gcd_1_count = 0;
        for(int i = 0; i<N; i++)
        {
          if(gcd_1[i] == 0)
          {
            for(int j = 0; j<N; j++)
            {
              if(i!=j)
              {
                if(gcd(A[i],A[j]) == 1)
                {
                  gcd_1[i] = 1;
                  gcd_1[j] = 1;
                }
              }
            }
          }
        }
        for(int i = 0; i<N; i++)
        {
          if(gcd_1[i] == 1)
          {
            gcd_1_count++;
          }
        }
        if(gcd_1_count == N)
        {
          cout<<"0\n";
          for(int i  = 0; i<N; i++)
          {
            cout<<A[i]<<" ";
          }
          cout<<"\n";
        }
        else
        {
          cout<<"1\n";
          cout<<"47 ";
          for(int i  = 1; i<N; i++)
          {
            cout<<A[i]<<" ";
          }
          cout<<"\n";
        }
      }
  }
    return 0;
}