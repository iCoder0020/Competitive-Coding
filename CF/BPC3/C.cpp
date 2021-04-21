#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	string P[N];
	vector<vector<int>>fwd(N,vector<int>(26, 0));
	vector<vector<int>>bwd(N,vector<int>(26, 0));
	for(int n = 0; n<N; n++)
	{
		cin>>P[n];
		int i;
		char x;
		
		i = 0;
		x = P[n][i];
		while(i<P[n].length() && x == P[n][i])
		{
			fwd[n][x-'a']++;
			i++;
		}

		i = P[n].length()-1;
		x = P[n][i];
		while(i>=0 && x == P[n][i])
		{
			fwd[n][x-'a']++;
			i++;
		}
	}
	vector<int>maxm(26,0);
	for(int n = 0; n<26; n++)
		maxm[n] = max(fwd[0][n], bwd[0][n]);
	for(int i = 1; i<N; i++)
	{
		
	}
	int maxm1 = *max_element(maxm.begin(), maxm.end());
	int maxm2 = 0;
	int curr = 0;
	int i = 0;
	char x = P[N-1][0];
	while(1)
	{
		if(i == P[N-1].length())
			break;
		if(P[N-1][i] == x)
			curr++;
		else
		{
			curr = 0;
			x = P[N-1][i];
		}
		if(curr > maxm2)
			maxm2 = curr;
		i++;
	}
	cout<<max(maxm1,maxm2)<<endl;
	return 0;
}
