#include <bits/stdc++.h>

using namespace std;

#define int long long

int min_dist(vector<int>&S, int x)
{
	int l = lower_bound(S.begin(), S.end(), x) - S.begin();
	int ans = abs(S[l]-x);
	if(l>0)
		ans = min(ans, abs(S[l-1]-x));
	return ans;
}

int32_t main()
{
	int N,M;
	cin>>N>>M;
	set<int>S2;
	set<int>S1;
	set<int>S;
	vector<int>P;
	int x;
	for(int n = 0; n<N; n++)
	{
		cin>>x;
		S.insert(x);
		S2.insert(x);
		P.push_back(x);
	}
	sort(P.begin(), P.end());
	int m = 0;
	set<int> answer;
	while(1)
	{
		for(auto it: S2)
		{
			if(S.find(it-1) == S.end())
				S1.insert(it-1);
			if(S.find(it+1) == S.end())
				S1.insert(it+1);
		}
		S2.clear();
		for(auto it: S1)
		{
			S.insert(it);
			S2.insert(it);
			answer.insert(it);
			m++;
			if(m == M)
				break;
		}
		if(m == M)
			break;
		S1.clear();
	}
	int sum = 0;
	for(auto it: answer)
		sum += min_dist(P, it);
	cout<<sum<<endl;
	for(auto it: answer)
		cout<<it<<" ";
	cout<<endl;
	return 0;
}
