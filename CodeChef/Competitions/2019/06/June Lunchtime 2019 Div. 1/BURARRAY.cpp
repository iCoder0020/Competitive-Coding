/*
ID: ishan_sang
PROG: BURARRAY
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long


map<int,int>rep;

void make_set(int x)
{
    rep[x] = x-1;
    if(rep.find(x-1) == rep.end())
    	rep[x-1] = x-1;
}

int find_set(int x)
{
	if(rep.find(x) == rep.end())
		return x;
    while(x != rep[x])
    {
        rep[x] = rep[rep[x]];
        x = rep[x];
    }
    return x;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int N, Q;
		cin>>N>>Q;
		int s = 0;
		rep.clear();
		while(Q--)
		{
			int t;
			cin>>t;
			if(t == 1)
			{
				int x;
				cin>>x;
				x += s;
				make_set(x);
			}
			else
			{
				int l,r;
				cin>>l>>r;
				l += s;
				r += s;	
				int ans;
				ans = find_set(r);
				if(ans<l)
					ans = 0;
				cout<<ans<<endl;
				s = (s%N+ans%N)%N;
			}
		}
	}
    return 0;
}