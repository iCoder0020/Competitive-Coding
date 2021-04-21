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
		int A[N];
		int B[N];
		map<int,int>mapA, mapB;
		set<int>S;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			mapA[A[n]]++;
			S.insert(A[n]);
		}
		for(int n = 0; n<N; n++)
		{
			cin>>B[n];
			mapB[B[n]]++;
			S.insert(B[n]);
		}
		vector<int>v;
		bool poss = true;
		for(auto it: S)
		{
			int d = abs(mapA[it]-mapB[it]);
			if(d&1)
				poss = false;
			for(int x = 0; x<d/2; x++)
				v.push_back(it);
		}
		if(!poss)
			cout<<-1;
		else
		{
			int ans1 = 0;
			for(int i = 0; i<v.size()/2; i++)
			{
				cout<<v[i]<<endl;
				ans1 += v[i];
			}
			for(int i = 0; i<v.size)
			cout<<min(ans1,ans2);
		}
		cout<<endl;
	}
	return 0;
}