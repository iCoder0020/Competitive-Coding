#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int TC;
  cin>>TC;
  while(TC--) {
    int N;
    cin>>N;
    vector<double>X(N);
    for(int n = 0; n<N; n++)
      cin>>X[n];
    vector<vector<double>>A(N, vector<double>(N,0));
    vector<vector<double>>B(N, vector<double>(N,0));
    for(int n = 0; n<N; n++)
      A[n][n] = X[n];
    for(int len = 2; len<=N; len++) {
      for(int i = 0; i<=N-len; i++) {
        int j = i+len-1;
        A[i][j] = 0.5*(B[i+1][j] + X[i]) + 0.5*(B[i][j-1] + X[j]);
        B[i][j] = 0.5*(A[i+1][j] + A[i][j-1]);
      }
    }
    cout<<fixed<<setprecision(15)<<A[0][N-1]<<endl;
  }
  return 0;
}