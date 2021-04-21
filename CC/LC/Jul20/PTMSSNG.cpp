#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		map<int,int>X;
		map<int,int>Y;
		int px, py;
		for(int n = 0; n<4*N-1; n++)
		{
			int x,y;
			cin>>x>>y;
			X[x]++;
			Y[y]++;
		}
		for(auto it: X)
			if((it.second)&1)
				px = it.first;
		for(auto it: Y)
			if((it.second)&1)
				py = it.first;
		cout<<px<<" "<<py<<endl;
	}
	return 0;
}