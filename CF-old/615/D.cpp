#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int Q, X;
	cin>>Q>>X;
	int number[X];
	for(int x = 0; x<X; x++)
		number[x] = x;
	set<int> curr;
	int mex = 0;
	while(Q--)
	{
		int y;
		cin>>y;
		int a = number[y%X];
		number[y%X]+=X;
		curr.insert(a);
		while(curr.find(mex) != curr.end())
		{
			curr.erase(mex);
			mex++;
		}
		cout<<mex<<endl;
	}
	return 0;
}
