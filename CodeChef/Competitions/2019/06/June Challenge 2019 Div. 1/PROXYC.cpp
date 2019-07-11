/*
ID: ishan_sang
PROG: PROXYC
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
        int D;
        cin>>D;
        string S;
        cin>>S;
        int p = 0; 
        int p_req = (int)(ceil(0.75*((double)D)));
        for(auto it: S)
        {
            if(it == 'P')
                p++;
        }
        if(p_req <= p)
            cout<<0;
        else
        {
            int cnt = p_req - p;
            for(int n = 2; n<D-2 && cnt; n++)
            {
                if(S[n] == 'A')
                {
                    if((S[n-1] == 'P' || S[n-2] == 'P') && (S[n+1] == 'P' || S[n+2] == 'P'))
                        cnt--;
                }
            }
            if(cnt == 0)
                cout<<p_req - p;
            else
                cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}