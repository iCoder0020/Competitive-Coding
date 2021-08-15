#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int N;
  cin>>N;
  vector<pair<int,int>>v1(2*N);
  vector<bool> redundant(N+1, true);
  for(int n = 0; n<N; n++) {
    cin>>v1[2*n].first>>v1[2*n+1].first;
    v1[2*n].second = -(n+1);
    v1[2*n+1].second = n+1;
  }
  sort(v1.begin(), v1.end());
  vector<pair<int,int>>v;
  for(int i = 0; i<2*N; i++) {
    v.push_back(v1[i]);
    if(i<2*N) {
      if(v1[i].first <= v1[i+1].first - 2) {
        v.push_back({v1[i].first+1, 0});
      }
    }
  }
  set<int> S;
  int i = 0;
  int sz = v.size();
  while(i<sz) {
    int t = v[i].first;
    vector<int>R;
    while(i<sz && t == v[i].first) {
      int idx = v[i].second;
      // cout<<t<<" "<<idx<<endl;
      if(idx < 0) {
        idx *= -1;
        S.insert(idx);
      } else if(idx>0) {
        R.push_back(idx);
      }
      i++;
    }
    if(S.size() == 1)
      redundant[*S.begin()] = false;
    for(int r: R)
      S.erase(S.find(r));
  }
  int idx = -1;
  for(int i = 1; i<=N; i++){
    if(redundant[i]) {
      idx = i;
      break;
    }
  }
  cout<<idx<<endl;
  return 0;
}