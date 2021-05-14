#include <bits/stdc++.h>

using namespace std;

#define int long long

int get(vector<char> &A, int N, int K)
{
	int ans = 0;
	int idx = 0;
	int cnt = 0;
	while(1)
	{
		if(A[idx] == '*')
			cnt++;
		if(cnt == K)
			break;
		idx++;
	}
	int x = idx-1;
	for(int i = idx-1; i>=0; i--)
	{
		if(A[i] == '*')
		{
			ans += x-i;
			x--;
		}
	}
	x = idx+1;
	for(int i = idx+1; i<N; i++)
	{
		if(A[i] == '*')
		{
			ans += i-x;
			x++;
		}
	}
	return ans;
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<char> A(N);
		int cnt = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n] == '*')
				cnt++;
		}
		int ans = -1;
		if(cnt <= 1)
			ans = 0;
		else
			ans = min(get(A, N, cnt/2), get(A, N, cnt/2 + 1));
		cout<<ans<<endl;
	}
	return 0;
}
