#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXW 1e4

int query(int i, int j) {
  cout<<1<<" "<<i<<" "<<j<<endl;
  fflush(stdout);
  int ans;
  cin>>ans;
  return ans;
}

int32_t main()
{
  int N;
  cin>>N;
  vector<int>P(N+1, 0);
  vector<int>W(N+1, 0);

  vector<int>M(N+1, 0);

  for(int i = 1; i<=N; i++) {
    M[i] = query(i, MAXW);
  }

  for(int i = 1; i<=N; i++) {
    P[i] = M[i] - M[i-1];
  }

  int pw = 0;

  for(int i = 1; i<=N; i++) {
    int lo = 1, hi = 100, mid;
    while(lo<hi) {
      mid = lo + (hi-lo)/2;
      if(query(i,mid+pw) < M[i]) {
        lo = mid+1;
      } else {
        hi = mid;
      }
    }
    W[i] = lo;
    pw += W[i];
  }

  cout<<2<<endl;
  fflush(stdout);

  for(int i = 1; i<=N; i++)
    cout<<W[i]<<" ";
  cout<<endl;
  fflush(stdout);

  for(int i = 1; i<=N; i++)
    cout<<P[i]<<" ";
  cout<<endl;
  fflush(stdout);

  return 0;
}