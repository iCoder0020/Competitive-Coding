#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int TC;
  cin>>TC;
  while(TC--) {
    int N,M,A,B;
    cin>>N>>M>>A>>B;
    vector<vector<char>>arr(N, vector<char>(M, '0'));
    int j = 0;
    for(int i = 0; i<N; i++) {
      int cnt = 0;
      while(cnt<A) {
        arr[i][j] = '1';
        cnt++;
        j = (j+1)%M;
      }
    }
    vector<int>row(N, 0);
    vector<int>col(M, 0);
    for(int i = 0; i<N; i++) {
      for(int j = 0; j<M; j++) {
        if(arr[i][j] == '1') {
          row[i]++;
          col[j]++;
        }
      }
    }
    bool poss = true;
    for(int i = 0; i<N; i++) {
      if(row[i] != A)
        poss = false;
    }
    for(int j = 0; j<M; j++) {
      if(col[j] != B)
        poss = false;
    }
    if(poss) {
      cout<<"YES"<<endl;
      for(auto it: arr) {
        for(auto jt: it)
          cout<<jt;
        cout<<endl;
      }
    } else {
      cout<<"NO"<<endl;
    }
  }
  return 0;
}