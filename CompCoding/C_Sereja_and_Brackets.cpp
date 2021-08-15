#include <bits/stdc++.h>
using namespace std;
#define int long long
#define left(v) v<<1
#define right(v) (v<<1) + 1

template <class T>
T operate(T const &a, T const &b) {
  int extra = 0;
  if(a[1]>0 && b[2]>0) {
    extra = min(a[1], b[2]);
  }
  return {a[0]+b[0]+2*extra, a[1]+b[1]-extra, a[2]+b[2]-extra};
}

template <class T>
class segmentTree {
  private:
    int n;
    T defValue;
    vector<T> arr;
    vector<T> segTree;
  public:
    segmentTree(vector<T> &arr, T defValue) {
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
    void build(int v, int tl, int tr) {
      if(tl == tr-1) {
        this->segTree[v] = this->arr[tl];
        return;
      }
      int tm = (tl+tr)>>1;
      build(left(v), tl, tm);
      build(right(v), tm, tr);
      this->segTree[v] = operate(this->segTree[left(v)], this->segTree[right(v)]);
    }
    T rangeQuery(int l, int r) {
      T resultL = this->defValue, resultR = this->defValue;
      for (l += this->n, r += this->n; l<r; l >>= 1, r >>= 1) {
        if (l&1) 
          resultL = operate(resultL, this->segTree[l++]);
        if (r&1) 
          resultR = operate(this->segTree[--r], resultR);
      }
      T result = operate(resultL, resultR);
      return result;
    }
    int getSize() {
      return this->n;
    }
};

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string S;
  cin>>S;
  vector<array<int,3>>a(S.length());
  for(int i = 0; i<S.length(); i++) {
    if(S[i] == '(') {
      a[i] = {0,1,0};
    } else {
      a[i] = {0,0,1};
    }
  }
  segmentTree<array<int,3>>T(a, {0,0,0});
  T.build(1, 0, T.getSize());
  int Q;
  cin>>Q;
  while(Q--) {
    int L,R;
    cin>>L>>R;
    cout<<T.rangeQuery(L-1, R)[0]<<endl;
  }
  return 0;
}