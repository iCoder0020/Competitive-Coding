/*
ID: ishan_sang
PROG: LENTMO
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        int s = 0;
        for(int n = 0; n<N; n++)
        {
            cin>>A[n];
            s += A[n];
        }
        int K,X;
        cin>>K>>X;
        priority_queue<pair<int,int>>pq1;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq2;
        for(int n = 0; n<N; n++)
        {
            int x = A[n]^X;
            if(x > A[n])
                pq1.push({x, n});
            else
                pq2.push({x, n});
        }
        for(int n = 0; n<(pq1.size()/K)*K; n++)
        {
            int t = pq1.top().first;
            int i = pq1.top().second;
            pq1.pop();
            s += t-A[i];
        }
        
        cout<<s<<endl;
    }
    return 0;
}