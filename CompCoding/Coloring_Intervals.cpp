#include <bits/stdc++.h>
using namespace std;
#define int long long

bool mySort(array<int,3>&A, array<int,3>&B){
  if(A[0] == B[0])
    return A[1] > B[1];
  return A[0]<B[0];
}

int32_t main()
{
  int TC;
  cin>>TC;
  while(TC--){
    int N;
    cin>>N;
    vector<int>colours(N);
    vector<array<int,3>>v(N);
    for(int n = 0; n<N; n++){
      int L,R;
      cin>>L>>R;
      v[n] = {L,R,n};
    }
    sort(v.begin(), v.end(), mySort);
    int l = 0;
    int maxR;
    int colour = 0;
    while(1){
      maxR = v[l][1];
      colours[v[l++][2]] = colour;
      colour = colour^1;
      while(l<N && v[l][0]<=maxR){
        colours[v[l++][2]] = colour;
      }
      if(l == N)
        break;
    }

    for(int n = 0; n<N; n++)
      cout<<colours[n];
    cout<<endl;
  }
  return 0;
}