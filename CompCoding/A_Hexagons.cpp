#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int TC;
  cin>>TC;
  while(TC--) {
    int X,Y;
    cin>>Y>>X;
    int C[6], oldC[6];
    for(int i = 0; i<6; i++)
      cin>>oldC[i];
    for(int i = 0; i<6; i++)
      C[i] = min(oldC[i], oldC[(i-1+6)%6] + oldC[(i+1)%6]);
    int ans = 0;
    if(X*Y > 0) {
      int common = 0;
      if(X<0) {
        common = max(X,Y);
        ans -= common*C[3];
      }
      else {
        common = min(X,Y);
        ans += common*C[0];
      }
      X -= common, Y -= common;
    }
    if(X>0)
      ans += X*C[1];
    if(X<0)
      ans -= X*C[4];
    if(Y>0)
      ans += Y*C[5];
    if(Y<0)
      ans -= Y*C[2];
    cout<<ans<<endl;
  }
  return 0;
}