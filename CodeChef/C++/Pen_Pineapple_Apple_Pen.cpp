#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXBITS 20

void addPen(vector<int> &penMap, int mask, int index) {
  if(penMap[mask] != 0)
    return;
  penMap[mask] = index;
  for(int i = 0; i<MAXBITS; i++) {
    if(mask & (1LL<<i)) {
      addPen(penMap, mask^(1LL<<i), index);
    }
  }
}

int getMask(string P) {
  int mask = 0;
  for(int i = 0; i<P.length(); i++) {
    mask |= 1LL<<(P[i] - 'a');
  }
  return mask;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int TC;
  cin>>TC;
  while(TC--) {
    int N, K;
    cin>>N>>K;
    string S;
    cin>>S;

    // make S 1-indexed
    S = "!" + S;

    // map penMask (and it's submasks) to pen index
    vector<int>penMap((1LL<<MAXBITS), 0);

    vector<string> P(K+1);

    for(int k = 1; k<=K; k++) {
      cin>>P[k];
      addPen(penMap, getMask(P[k]), k);
    }

    // freq[i][j] -> #times character j+'a' occurs till ith index
    vector<vector<int>>freq(N+1, vector<int>(MAXBITS, 0));
    for(int i = 1; i<=N; i++) {
      freq[i][S[i]-'a']++;
      for(int j = 0; j<MAXBITS; j++) {
        freq[i][j] += freq[i-1][j];
      }
    }

    vector<int>ans(N+1);

    for(int i = N; i>=1; i--) {
      // binary search to find j: S[j...i] can be written using only 1 pen
      int lo = 1, mid, hi = i;
      int ansMask = 1LL<<(S[i]-'a');
      while(lo<hi) {
        mid = lo + (hi-lo)/2;
        int mask = 0;
        for(int j = 0; j<MAXBITS; j++) {
          if(freq[i][j] - freq[mid-1][j] > 0) {
            mask |= (1LL<<j);
          }
        }
        if(penMap[mask] == 0) {
          lo = mid+1;
        } else {
          ansMask = mask;
          hi = mid;
        }
      }
      for(int k = lo; k<=i; k++)
        ans[k] = penMap[ansMask];
      i = lo;
    }

    for(int n = 1; n<=N; n++)
      cout<<ans[n]<<" ";

    cout<<endl;
  }
  return 0;
}