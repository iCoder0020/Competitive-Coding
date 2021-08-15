#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int TC;
  cin>>TC;
  while(TC--){
    double N,Q;
    cin>>N>>Q;
    double ans = Q + (N*Q)/(Q+1);
    cout<<fixed<<setprecision(10)<<ans<<endl;
  }
  return 0;
}