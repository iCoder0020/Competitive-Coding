#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T> 
struct segmentTree {
  int n;
  T def;
  function<T(T, T)> op;
  vector<T> segTree;

  segmentTree(vector<T> &arr, T def, function<T(T, T)> op) : def{def}, op{op} {
    n = arr.size();
    segTree.resize(2*n, def);
    for(int i = n; i<2*n; i++) {
      segTree[i] = arr[i-n];
    }
  }
  void build() {
    for(int i = n-1; i>0; i--)
      segTree[i] = op(segTree[i<<1], segTree[i<<1|1]);
  }
  void pointUpdate(int p, T newVal) {
    for(segTree[p += n] = newVal; p>1; p >>= 1) 
      segTree[p>>1] = op(segTree[p], segTree[p^1]);
  }
    T rangeQuery(int l, int r) {
    T resultL = def, resultR = def;
    for(l += n, r += n; l<r; l >>= 1, r >>= 1) {
      if (l&1) 
        resultL = op(resultL, segTree[l++]);
      if (r&1) 
        resultR = op(segTree[--r], resultR);
    }
    T result = op(resultL, resultR);
    return result;
  }
  void rangeOperate(int l, int r, T val) {
    for(l += n, r += n; l<r; l >>= 1, r >>= 1) {
      if (l&1)
        segTree[l++] = op(segTree[l], val);
      if (r&1)
        segTree[r] = op(segTree[--r], val);
    }
  }
  T pointQueryAfterRangeOperate(int p) {
    T result = def;
    for(p += n; p>0; p >>= 1) 
      result = op(result, segTree[p]);
    return result;
  }
  T getElement(int p) {
    return segTree[p+n];
  }
  void printSegTree() {
    for(T x: segTree) {
      cout<<x<<" ";
    }
    cout<<endl;
  }
};

int32_t main()
{
  int N;
  cin>>N;
  vector<int>A(N);
  for(int &x: A)
    cin>>x;
  segmentTree<int>T(A, 0, [](int a, int b){return a+b;});
  T.build();
  cout<<T.rangeQuery(0, N)<<endl;
  return 0;
}