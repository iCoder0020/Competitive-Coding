/*
ID: code_lite
PROG: QABC
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long T;
    cin>>T;
    while(T--)
    {
      long long n;
      cin>>n;
      long long A[n],B[n];
      for(long long i=0;i<n;i++)
      {
        cin>>A[i];
      }
      for(long long i=0;i<n;i++)
      {
        cin>>B[i];
      }
      long long current_index=0;
      while(true)
      {
        if(A[current_index]>B[current_index])
        {
          cout<<"NIE\n";
          break;
        }
        else if(A[current_index]==B[current_index])
        {
          current_index++;
          if(current_index>=n)
          {
            cout<<"TAK\n";
            break;
          }
        }
        else
        {
          if(current_index+2>=n)
          {
            cout<<"NIE\n";
            break;
          }
          else
          {
            long long diff = B[current_index] - A[current_index];
            A[current_index] += 1*diff;
            A[current_index+1] += 2*diff;
            A[current_index+2] += 3*diff;
            current_index++;
          }
        }
      }
    }
    return 0;
}