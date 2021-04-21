#include <bits/stdc++.h>

using namespace std;

#define int long long

int solve(string &S, int l, int r, char c)
{
	int N = r-l;
	if(N==1)
	{
		if(S[l] == c)
			return 0;
		else
			return 1;
	}
	int cnt1 = N/2, cnt2 = N/2;
	int mid = (l+r)/2;
	for(int n = l; n<mid; n++)
		if(S[n] == c)
			cnt1--;
	for(int n = mid; n<r; n++)
		if(S[n] == c)
			cnt2--;
	if(cnt1 == 0)
		return solve(S,mid,r,c+1);
	if(cnt2 == 0)
		return solve(S,l,mid,c+1);
	return min(cnt1 + solve(S, mid, r, c+1), cnt2 + solve(S, l, mid, c+1));
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		string S;
		cin>>S;
		cout<<solve(S,0,N,'a')<<endl;
	}
	return 0;
}