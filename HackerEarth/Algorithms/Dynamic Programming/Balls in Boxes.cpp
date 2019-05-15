/*
ID: icoder_0020
PROG: Balls in Boxes
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e18
#define N_MAX 1024

int to_int(string a)
{
    reverse(a.begin(), a.end());
    int x = 0;
    for(int i = 0; i<10; i++)
        if(a[i] == '1')
            x+=1<<i;
    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    int cost[N];
    string comb[N];
    for(int n = 0; n<N; n++)
        cin>>cost[n]>>comb[n];
    vector<int>w(N_MAX, INF);
    w[0] = 0;
    for(int n = 0; n<N; n++)
    {
        int box = to_int(comb[n]);
        w[box] = min(w[box], cost[n]);
    }
    for(int i = 0; i<N_MAX; i++)
        for(int j = 0; j<N_MAX; j++)
            w[i|j] = min(w[i|j], w[i]+w[j]);  
    for(int n = N_MAX-1; n>=0; n--)
    {
        if(w[n] != INF)
        {
            cout<<w[n]<<endl;
            break;
        }
    }
    return 0;
}