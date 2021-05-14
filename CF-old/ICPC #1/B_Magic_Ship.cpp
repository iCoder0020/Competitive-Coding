#include <bits/stdc++.h>

using namespace std;

#define int long long

bool poss(vector<vector<int>>&A, int K, int X1, int X2, int Y1, int Y2)
{
    int N = A.size()-1;
    int y = (K/N)*A[N][0] + A[K%N][0];
    int x = (K/N)*A[N][1] + A[K%N][1];
    X1 += x, Y1 += y;
    return abs(X2-X1) + abs(Y2-Y1) <= K;
}

int32_t main()
{
	int X1, Y1, X2, Y2;
    cin>>X1>>Y1>>X2>>Y2;
    int N;
    cin>>N;
    string S;
    cin>>S;
    vector<vector<int>>prefix(N+1, vector<int>(2,0));
    for(int n = 1; n<=N; n++)
    {
        if(n != 1)
            for(int i = 0; i<2; i++)
                prefix[n][i] += prefix[n-1][i];
        switch(S[n-1])
        {
            case 'U':
            prefix[n][0]++;
            break;

            case 'L':
            prefix[n][1]--;
            break;

            case 'D':
            prefix[n][0]--;
            break;

            case 'R':
            prefix[n][1]++;
            break;
        }
    }
    int lo = 0, hi = 1e18, mid;
    while(lo<hi)
    {
        mid = lo + (hi-lo)/2;
        if(poss(prefix, mid, X1, X2, Y1, Y2))
            hi = mid;
        else
            lo = mid+1;
    }
    if(lo == 1e18)
        lo = -1;
    cout<<lo<<endl;
	return 0;
}
