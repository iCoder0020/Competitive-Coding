#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int N;
  cin>>N;
  vector<int>arr(N);
  for(int n = 0; n<N; n++)
    cin>>arr[n];
  if(N<50) {
    int ans = N;
    for(int i = 0; i<N-2; i++) {
      if((arr[i]^arr[i+1])>arr[i+2]) {
        ans = 1;
      }
    }
    for(int i = N-1; i>=2; i--) {
      if((arr[i]^arr[i-1])<arr[i-2])
        ans = 1;
    }
    for(int l = 0; l<N; l++) {
      for(int m = l; m<N; m++) {
        for(int r = m; r<N; r++){
          int L = 0, R = 0;
          for(int i = l; i<=m; i++)
            L ^= arr[i];
          for(int i = m+1; i<=r; i++)
            R ^= arr[i];
          if(l == m)
            L = (l==0)?INT_MIN:arr[l-1];
          if(r == m)
            R = (r==N-1)?INT_MAX:arr[r+1];
          if(L>R) {
            if(m == l && m == r)
              ans = min(ans, N);
            else if(m == l)
              ans = min(ans, r-m);
            else if(m == r)
              ans = min(ans, m-l);
            else
              ans = min(ans, r-l-1);
            // cout<<l<<" "<<m<<" "<<r<<endl;
            // cout<<L<<" "<<R<<endl;
          }
        }
      }
    }
    ans = (ans == N)?-1:ans;
    cout<<ans<<endl;
  } else {
    cout<<1<<endl;
  }
  return 0;
}