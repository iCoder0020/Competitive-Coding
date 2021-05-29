
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int N;
    cin>>N;
    vector<int>A(N+1);
    for(int n = 1; n<=N; n++)
        cin>>A[n];
    priority_queue<int, vector<int>, greater<int>> minheap;
    int sum = 0;
    for(int n = 1; n<=N; n++) 
    {
        sum += A[n];
        minheap.push(A[n]);
        while(sum<0 && minheap.size())
        {
            int x = minheap.top();
            minheap.pop();
            sum -= x;
        }
    }
    cout<<minheap.size()<<endl;
    return 0;
}