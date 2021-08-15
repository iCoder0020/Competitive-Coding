#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int TC;
    cin>>TC;
    int A[1200] = {0};
    queue<int>Q;
    Q.push(11);
    Q.push(111);
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        // cout<<x<<endl;
        if(x + 11 < 1200 and (A[x] == 0))
            Q.push(x+11);
        if(x + 111 < 1200 and (A[x] == 0))
            Q.push(x+111);
        A[x] = 1;
    }
    while(TC--)
    {
        int N;
        cin>>N;
        bool poss = false;
        if(N>=1200 || A[N] == 1)
            poss = true;
        cout<<((poss)?"YES":"NO");
        cout<<endl;
    }
    return 0;
}