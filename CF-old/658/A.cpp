#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,M;
		cin>>N>>M;
		set<int>A,B;
		for(int n = 0; n<N; n++)
		{
			int x;
			cin>>x;
			A.insert(x);
		}
		for(int m = 0; m<M; m++)
		{
			int x;
			cin>>x;
			B.insert(x);
		}
		int a = -1;
		for(auto it: A)
			if(B.find(it)!=B.end())
				a = it;
		if(a==-1)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			cout<<1<<" "<<a<<endl;
		}

	}
	return 0;
}
