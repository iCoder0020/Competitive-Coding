#include <bits/stdc++.h>
using namespace std;
#define int long long
#define left(v) v<<1
#define right(v) (v<<1) + 1

template <class T>
T operate(T const &a, T const &b) {
  return a+b;
}

template <class T>
class segmentTree {
  private:
    int n;
    T defValue;
    vector<T> arr;
    vector<T> segTree;
  public:
    segmentTree(vector<int> &arr, T defValue) {
      this->defValue = defValue;
      this->n = roundUpToNearestPowerOf2(arr.size());
      this->arr.resize(this->n, this->defValue);
      for(int i = 0; i<arr.size(); i++) {
        this->arr[i] = arr[i];
      }
      this->segTree.resize(2*this->n, this->defValue);
    }
    int roundUpToNearestPowerOf2(int x) {
      return pow(2, ceil(log2(x)));
    }
    void build() {
      for(int i = this->n-1; i>0; i--) 
        this->segTree[i] = operate(this->segTree[i<<1], this->segTree[i<<1|1]);
    }
    void pointUpdate(int p, T newVal) {
      for (this->segTree[p += this->n] = newVal; p>1; p >>= 1) 
        this->segTree[p>>1] = operate(this->segTree[p], this->segTree[p^1]);
    }
    T rangeQuery(int l, int r) {
      T result = this->defValue;
      for (l += this->n, r += this->n; l<r; l >>= 1, r >>= 1) {
        if (l&1) 
          result = operate(result, this->segTree[l++]);
        if (r&1) 
          result = operate(result, this->segTree[--r]);
      }
      return result;
    }
    void rangeOperate(int l, int r, T val) {
      for (l += this->n, r += this->n; l<r; l >>= 1, r >>= 1) {
        if (l&1)
          this->segTree[l++] = operate(this->segTree[l], val);
        if (r&1)
          this->segTree[r] = operate(this->segTree[--r], val);
      }
    }
    T pointQueryAfterRangeOperate(int p) {
      T result = this->defValue;
      for (p += this->n; p>0; p >>= 1) 
        result = operate(result, this->segTree[p]);
      return result;
    }
    void printArray() {
      for(T x: arr) {
        cout<<x<<" ";
      }
      cout<<endl;
    }
    void printSegTree() {
      for(T x: segTree) {
        cout<<x<<" ";
      }
      cout<<endl;
    }
    int getSize() {
      return this->n;
    }
};

int N;
vector<vector<int>>g;
vector<vector<pair<int,int>>>queries;
vector<int>ans;

void dfs(segmentTree<int> &T, int u, int p, int d) {
  for(pair<int,int>q: queries[u]) {
    int k = q.first;
    int x = q.second;
    T.rangeOperate(d, min(d+k,N)+1, x);
  }
  ans[u] = T.pointQueryAfterRangeOperate(d);
  for(int v: g[u]) {
    if(v == p) 
      continue;
    dfs(T, v, u, d+1);
  }
  for(pair<int,int>q: queries[u]) {
    int k = q.first;
    int x = q.second;
    T.rangeOperate(d, min(d+k,N)+1, -x);
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N;
  vector<int> heightArr(N, 0);
  segmentTree<int> T(heightArr, 0);
  T.build();
  ans.resize(N+1);
  g.resize(N+1);
  queries.resize(N+1);  
  for(int n = 0; n<N-1; n++) {
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int Q;
  cin>>Q;
  while(Q--) {
    int v, d, x;
    cin>>v>>d>>x;
    queries[v].push_back({d,x});
  }
  dfs(T, 1, 0, 0);
  for(int u = 1; u<=N; u++) {
    cout<<ans[u]<<" ";
  }
  cout<<endl;
  return 0;
}