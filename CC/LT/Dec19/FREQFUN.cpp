#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int>A(N);
		vector<int>B(N, 0);
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n] != -1)
				B[A[n]]++;
		}
		vector<int>G(N+1);
		for(int n = 0; n<N+1; n++)
			cin>>G[n];	
		int check_total = 0;
		for(int n = 0; n<N+1; n++)
			check_total += n*G[n];
		if(check_total != N)
			cout<<"impossible";
		else
		{
			int A_idx = 0;
			for(int n = N; n>=0; n--)
			{
				if(G[n] > 0)
				{
					while(A_idx<N && A[A_idx]!=-1)
						A_idx++;
					if(A_idx < N)
					{
					
					}
				}
			}

			int flag = true;
			for(int n = 0; n<N+1; n++)
			{
				if(G[n] != 0)
				{
					flag = false;
					break;
				}
			}
			for(int n = 0; n<N; n++)
			{
				if(A[n] == -1)
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				for(auto it: A)
					cout<<it<<" ";
			}
			else
			{
				cout<<"impossible";
			}
		}
		cout<<endl;
	}
	return 0;
}