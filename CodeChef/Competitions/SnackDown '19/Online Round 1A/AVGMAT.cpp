/*
ID: code_lite
PROG: AVGMAT
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
      long long N,M;
      cin>>N>>M;
      long long range = N+M-2;
      char arr[N][M];
      for(long long n=0;n<N;n++)
      {
        for(long long m=0;m<M;m++)
        {
          cin>>arr[n][m];
        }
      }
      for(long long d=1;d<=range;d++)
      {
        long long count=0;
        for(long long i=0;i<N;i++)
        {
          for(long long j=0;j<M;j++)
          {
            for(long long k=0;k<N;k++)
            {
              for(long long l=0;l<M;l++)
              {
                if(arr[i][j]=='1' && arr[k][l]=='1')
                {
                  if(abs(i-k)+abs(j-l)==d)
                  {
                    count++;
                  }
                }
              }
            } 
          }
        }
        cout<<count/2<<" "; 
      }
      cout<<"\n";
    }
    return 0;
}