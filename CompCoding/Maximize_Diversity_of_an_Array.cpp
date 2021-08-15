#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int TC;
  cin>>TC;
  while(TC--){
    int N,K;
    cin>>N>>K;
    map<int,int>freq;
    for(int n = 0; n<N; n++){
      int x;
      cin>>x;
      freq[x]++;  
    }
    priority_queue<int>max_heap;
    for(auto it: freq){
      if(it.second>=2){
        max_heap.push(it.second);
      }
    }
    for(int i = 0; i<K; i++){
      if(max_heap.empty())
        break;
      int p = max_heap.top();
      max_heap.pop();
      if(p > 2)
        max_heap.push(p-1);
    }
    int sub = 0;
    while(!max_heap.empty()){
      int p = max_heap.top();
      max_heap.pop();
      sub += (p*(p-1))/2;
    }
    cout<<(N*(N-1))/2 - sub<<endl;
  }
  return 0;
}