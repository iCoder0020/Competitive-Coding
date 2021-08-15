#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int TC;
    cin>>TC;
    while(TC--)
    {
        int N;
        cin>>N;
        string S, revS;
        cin>>S;
        revS = S;
        reverse(revS.begin(), revS.end());
        int zero = 0;
        for(char x: S)
            zero = (x=='0')?zero+1:zero;
        if(zero == 1)
            cout<<"BOB";
        else if(zero == 2)
            cout<<"BOB";
        else if(zero&1)
            cout<<"ALICE";
        else
            cout<<"BOB";
        cout<<endl;
    }
    return 0;
}