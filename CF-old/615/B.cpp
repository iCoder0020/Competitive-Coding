#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x(n) points[n].first
#define y(n) points[n].second

string extra(int x1, int y1, int x2, int y2)
{
	string S = "";
	for(int i = 0; i<x2-x1; i++)
		S += 'R';
	for(int i = 0; i<y2-y1; i++)
		S += 'U';
	return S;
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<pair<int,int>> points(N);
		for(int n = 0; n<N; n++)
			cin>>x(n)>>y(n);
		sort(points.begin(), points.end());
		bool pos = true;
		int X = 0, Y = 0;
		string ans = "";
		for(int n = 0; n<N; n++)
		{
			if(X<=x(n) && Y<=y(n))
			{
				ans += extra(X,Y,x(n),y(n));
				X = x(n);
				Y = y(n);
			}
			else
			{
				pos = false;
				break;
			}
		}	
		if(pos)
			cout<<"YES"<<endl<<ans<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
