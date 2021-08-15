#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>parent;
vector<int>sz;

void create(int u) {
  parent[u] = u;
  sz[u] = 1;
}

int getParent(int u) {
  if(parent[u] == u)
    return u;
  return getParent(parent[u]);
}

void merge(int a, int b) {
  int pa = getParent(a);
  int pb = getParent(b);
  if(pa == pb)
    return;
  if(sz[pa] < sz[pb]) {
    parent[pb] = pa;
    sz[pa] += sz[pb];
  } else {
    parent[pa] = pb;
    sz[pb] += sz[pa];
  }
}

int32_t main()
{
  int TC;
  cin>>TC;
  while(TC--) {
    // input
    int N,K;
    cin>>N>>K;
    vector<vector<pair<int,int>>>heights(K+1);
    for(int i = 0; i<N; i++) {
      for(int j = 0; j<N; j++) {
        int h;
        cin>>h;
        heights[h].push_back({i,j});
      }
    }

    // create graph
    vector<vector<array<int,3>>>edges(K+1);
    for(int k = 1; k<K; k++) {
      for(pair<int,int> up: heights[k]) {
        int u = up.first*N + up.second;
        for(pair<int,int> vp: heights[k+1]) {
          int v = vp.first*N + vp.second;
          edges[k].push_back({abs(up.first-vp.first)+abs(up.second-vp.second),u,v});
        }
      }
    }

    // sort acc to edge weight
    for(int k = 1; k<K; k++)
      sort(edges[k].begin(), edges[k].end());

    
    // dsu time
    parent.resize(N*N);
    sz.resize(N*N, 0);

    for(int i = 0; i<N*N; i++)
      create(i);

    int minCost = INT_MAX;

    for(array<int,3>e: edges[1]) {
      int w = e[0];
      int u = e[1];
      int v = e[2];
      for(int k = 2; k<N; k++) {
        
      }
    }

    cout<<minCost<<endl;
  }
  return 0;
}