/*
ID: code_lite
PROG: TYPING
LANG: C++                  
*/

#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    long long T;
    int hand;
    cin>>T;
    while(T--)
    {
      long long N;
      cin>>N;
      string A[N];
      long double time[N]={0};
      int flag=0;
      for(long long i=0;i<N;i++)
      {
        cin>>A[i];
        flag=0;
        for(long long j=0;j<i;j++)
        {
          if((A[i].compare(A[j])) == 0)
          {
            time[i] = time[j]/2;
            flag=1;
            break;
          }
        }
       if(flag==0)
        {
          for(long long k=0;k<A[i].length();k++)
          {
            if(k==0)
            {
              if(A[i][k]=='d' || A[i][k]=='f')
              {
                hand=0;
              }
              else
              {
                hand=1;
              }
              time[i]+=0.2;
            }
            else
            {
              if(hand==0)
              {
                if(A[i][k]=='d' || A[i][k]=='f')
                {
                  time[i]+= 0.4;
                }
                else
                {
                  hand=1;
                  time[i]+= 0.2;
                }
              }
              else
              {
                if(A[i][k]=='d' || A[i][k]=='f')
                {
                   hand=0;
                  time[i]+= 0.2;
                }
                else
                {
                  time[i]+= 0.4;
                }
              }
            }
          }          
        }
      }
    long double sum_time=0;
    for(long long i=0;i<N;i++)
    {
      sum_time = sum_time + time[i];
    }
    cout<<sum_time*10<<"\n";
    }
    return 0; 
} 