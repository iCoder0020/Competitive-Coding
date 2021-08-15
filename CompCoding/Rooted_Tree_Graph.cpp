#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int TC;
  cin>>TC;
  while(TC--){
    int N,M;
    cin>>N>>M;
    vector<vector<int>>g(N+1);
    for(int m = 0; m<M; m++){
      int u,v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  return 0;
}