#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin>>TC;
    for(int tc = 0; tc<TC; tc++)
    {
        int N;
        cin>>N;
        string S;
        cin>>S;
        int a = 0, b = 0;
        for(auto it: S)
        {
            if(it == 'A')
                a++;
            else
                b++;
        }
        char ans = 'N';
        if(max(a,b)<=(N+1)/2)
            ans = 'Y';
        cout<<"Case #"<<tc+1<<": "<<ans<<endl;
    }
    return 0;
}