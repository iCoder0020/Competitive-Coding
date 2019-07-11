/*
ID: ishan_sang
PROG: SUMAGCD
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
        for(int n = 0; n<N; n++)
            cin>>A[n];
        sort(A, A+N);
        vector<int>B;
        B.push_back(A[0]);
        for(int n = 1; n<N; n++)
            if(A[n] != A[n-1])
                B.push_back(A[n]);
        N = B.size();
        if(N == 1)
            cout<<2*B[0]<<endl;
        else
        {
            int gcd, pre_gcd, maxm;
            int max_ans = 0;
            maxm = B[N-1];
            int l_cand = lower_bound(B.begin(), B.end(), maxm/2)-B.begin();
            pre_gcd = B[0];
            for(int n = 1; n<l_cand; n++)
            {
                pre_gcd = __gcd(pre_gcd, B[n]);
                if(pre_gcd == 1)
                    break;
            }
            for(int n = N-1; n>=l_cand; n--)
            {
                gcd = pre_gcd;
                maxm = B[n];
                for(int m = l_cand; m<N; m++)
                {
                    if(B[m] != maxm)
                        gcd = __gcd(gcd, B[m]);
                    if(gcd == 1 || gcd + maxm <= max_ans)
                        break;
                }
                max_ans = max(max_ans,maxm + gcd);
                while(n-1>=l_cand && B[n] == B[n-1])
                    n--;
            }
            cout<<max_ans<<endl;
        }
    }
    return 0;
}