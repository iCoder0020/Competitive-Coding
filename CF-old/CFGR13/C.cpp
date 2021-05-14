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
		int sum = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			sum += A[n];
		}
		int moves = 0;
		int start = 0;
		while(sum > N)
		{
			int idx = start;
			while(A[idx] == 1)
				idx++;
			start = idx;
			moves += 1;
			int next_idx = idx + A[idx];
			if(next_idx >= N)
			{
				if(idx == N-1)
					moves--;
				moves += next_idx-N;
				sum -= A[idx];
				A[idx] = max(1LL,(N-1)-idx);
				sum += A[idx];
			}
			else
			{
				while(idx<N)
				{
					int jump_idx = idx+A[idx];
					if(A[idx] > 1)
					{			
						A[idx]--;
						sum--;
					}
					idx = jump_idx;				
				}
			}
		}
		cout<<moves<<endl;
	}
	return 0;
}
