/*
ID: code_lite
PROG: BUDDYNIM
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int T,N,M;
    cin>>T;
    for(int t = 0; t<T; t++)
    {
      bool bot = true;
      cin>>N>>M;
      vector<long long int> A;
      vector<long long int> B;
      int temp;
      for(int n = 0; n<N; n++)
      {
        cin>>temp;
        if(temp != 0)
        {
          A.push_back(temp);
        }
      }
      for(int m = 0; m<M; m++)
      {
        cin>>temp;
        if(temp != 0)
        {
          B.push_back(temp);
        }
      }
      sort(A.begin(), A.end());
      sort(B.begin(), B.end());
      if(A.size() == B.size())
      {
        for(int n = 0; n<A.size(); n++)
        {
          if(A[n] != B[n])
          {
            bot = false;
            break;
          }
        }
        if(bot)
        {
          cout<<"Bob";
        }
        else
        {
          cout<<"Alice";
        }
      }
      else
      {
        cout<<"Alice";
      }
      cout<<endl;
    }
    return 0;
}