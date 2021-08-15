#include <bits/stdc++.h>
using namespace std;
#define int long long

template <class T>
T operate(T const &a, T const &b) {
  if(a.first == b.first) {
    if(a.second < b.second)
      return a;
    else 
      return b;
  }
  if(a.first > b.first)
    return a;
  return b;
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
    void build() {
      for(int i = this->n-1; i>0; i--) 
        this->segTree[i] = operate(this->segTree[i<<1], this->segTree[i<<1|1]);
    }
    void pointUpdate(int p, T newVal) {
      for(this->segTree[p += this->n] = newVal; p>1; p >>= 1) 
        this->segTree[p>>1] = operate(this->segTree[p], this->segTree[p^1]);
    }
     T rangeQuery(int l, int r) {
      T resultL = this->defValue, resultR = this->defValue;
      for(l += this->n, r += this->n; l<r; l >>= 1, r >>= 1) {
        if (l&1) 
          resultL = operate(resultL, this->segTree[l++]);
        if (r&1) 
          resultR = operate(this->segTree[--r], resultR);
      }
      T result = operate(resultL, resultR);
      return result;
    }
    T getElement(int p) {
      return this->segTree[p+this->n];
    }
    void printArray() {
      for(T x: arr) {
        cout<<x<<" ";
      }
      cout<<endl;
    }
    void printSegTree() {
      for(T x: segTree) {
        cout<<x.first<<", "<<x.second<<endl;
      }
      cout<<endl;
    }
    int getSize() {
      return this->n;
    }
};

int32_t main()
{
  int TC;
  cin>>TC;
  while(TC--) {
    int N,K;
    cin>>N>>K;
    vector<int>A(N+1);
    for(int n = 1; n<=N; n++)
      cin>>A[n];

    vector<pair<int,int>>preSorted(N+1, {0,0});

    for(int n = 1; n<=N; n++)
      preSorted[n] = {preSorted[n-1].first + A[n], n};

    sort(preSorted.begin(), preSorted.end());

    // idxSorted[i] = index of ith element in preSorted array
    vector<int> idxSorted(N+1, 0);

    for(int i = 0; i<=N; i++){
      idxSorted[preSorted[i].second] = i;
    }

    // for(int i = 0; i<=N; i++){
    //   cout<<idxSorted[i]<<" ";
    // }
    // cout<<endl;

    // jIndex[i] = max index j: preSorted[j] < preSorted[i]
    vector<int> jIndex(N+1, -1);

    int lastPrefix = preSorted[0].first;
    for(int i = 1; i<=N; i++) {
      if(preSorted[i].first == lastPrefix)
        jIndex[i] = jIndex[i-1];
      else {
        lastPrefix = preSorted[i].first;
        jIndex[i] = i-1;
      }
    }

    // dp[i] = (max #partitions possible for A[1...i], j)
    // over all j: j<=i && A[j...i] > 0 && dp[j] + 1 is maxm
    vector<pair<int,int>>dp(N+1, {LLONG_MIN, -1});

    segmentTree<pair<int,int>>T(dp, {LLONG_MIN, -1});

    T.pointUpdate(idxSorted[0], {0, 0});

    for(int i = 1; i<=N; i++){
      // T.printSegTree();
      int dpj, j;
      tie(dpj, j) = T.rangeQuery(0, jIndex[idxSorted[i]]+1);
      if(dpj == LLONG_MIN || j == -1)
        dp[i] = {LLONG_MIN, -1};
      else
        dp[i] = {dpj+1, j};
      T.pointUpdate(idxSorted[i], {dp[i].first, i});
      // cout<<"dp["<<i<<"]: "<<dp[i].first<<","<<dp[i].second<<endl;
    }
    if(dp[N].first < K) {
      cout<<"NO";
    } else {
      cout<<"YES"<<endl;
      vector<int>ans;
      int i = N;
      int cnt = 0;
      while(i >= 1) {
        cnt++;
        int j = dp[i].second;
        if(cnt == K)
          j = 0;
        ans.push_back(i-j);
        i = j;
      }
      reverse(ans.begin(), ans.end());
      for(int x: ans) 
        cout<<x<<" ";
    }
    cout<<endl;
  }
  return 0;
}