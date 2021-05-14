#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,M;
	cin>>N>>M;
	string S[N];
	set<int> idx;
	vector<pair<int,int>> pairs;
	string same = "";
	for(int n = 0; n<N; n++)
		cin>>S[n];
	for(int i = 0; i<N-1; i++)
	{
		for(int j = i+1; j<N; j++)
		{
			if((idx.find(i) == idx.end())&&(idx.find(j) == idx.end()))
			{
				reverse(S[i].begin(), S[i].end());
				if(S[i] == S[j])
				{
					idx.insert(i);
					idx.insert(j);
					pairs.push_back({i,j});
				}
				reverse(S[i].begin(), S[i].end());
			}
		}
	}
	for(int i = 0; i<N; i++)
	{
		string temp = S[i];
		reverse(temp.begin(), temp.end());
		if(temp == S[i])
			same = temp;
	}
	string pal = "";

	int x = pairs.size();
	int y = same.size();

	if(x == 0 && y == 0)
		cout<<0<<endl;
	else
	{
		for(int n = 0; n<x; n++)
			pal += S[pairs[n].first];
		pal += same;
		for(int n = x-1; n>=0; n--)
			pal += S[pairs[n].second];
		cout<<pal.length()<<endl<<pal<<endl;
	}
	return 0;
}
