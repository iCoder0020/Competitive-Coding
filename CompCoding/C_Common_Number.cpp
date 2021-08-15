#include <bits/stdc++.h>
using namespace std;
#define int long long

int count(int x, int N) {
  queue<int>Q;
  Q.push(x);
  int cnt = 0;
  while(!Q.empty()) {
    int q = Q.front();
    cnt++;
    Q.pop();
    if(q*2 <= N)
      Q.push(q*2); 
    if(q%2 == 0 && q+1<=N)
      Q.push(q+1);
  }
  return cnt;
}

int32_t main()
{
  int N,K;
  cin>>N>>K;
  int lo = 1, mid, hi=N/2;
  while(lo<hi) {
    mid = lo + (hi-lo+1)/2;
    if(count(2*mid, N)>=K) {
      lo = mid;
    } else {
      hi = mid-1;
    }
  }
  int ans = 1;
  if(2*lo<=N && count(2*lo, N)>=K)
    ans = max(ans, 2*lo);

  lo = 1, mid, hi=N/2;
  while(lo<hi) {
    mid = lo + (hi-lo+1)/2;
    if(count(2*mid-1, N)>=K) {
      lo = mid;
    } else {
      hi = mid-1;
    }
  }
  if(2*lo-1<=N && count(2*lo-1, N)>=K)
    ans = max(ans, 2*lo-1);
  cout<<ans<<endl;
  return 0;
}