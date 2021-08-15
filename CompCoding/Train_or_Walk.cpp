#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int TC;
  cin>>TC;
  while(TC--){
    int N,A,B,C,D,P,Q,Y;
    cin>>N>>A>>B>>C>>D>>P>>Q>>Y;
    int X[N+1];
    for(int n = 1; n<=N; n++)
      cin>>X[n];
    int ans = abs(X[A]-X[B])*P;
    if(abs(X[A]-X[C])*P<=Y)
      ans = min(ans, Y + abs(X[C]-X[D])*Q + abs(X[D]-X[B])*P);
    cout<<ans<<endl;
  }
  return 0;
}