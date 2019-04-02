/*
ID: ishan_sang
PROG: MARCAPS
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int A[N];
		int ans[N] = {0};
		map<int,int>M;
		int max_count = 0;
		int max_num;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(M.find(A[n]) == M.end())
				M[A[n]] = 1;
			else
				M[A[n]]++;
			if(max_count <= M[A[n]])
			{
				max_count = M[A[n]];
				max_num = A[n];
			}
		}

		if(2*max_count<=N)
		{
			for(int n = 0; n<N; n++)
			{
				if(A[n] != max_num)
				{
					ans[n] = max_num;
					M[max_num]--;
					if(M[max_num] == 0)
					{
						M.erase(max_num);
						break;
					}
				}
			}
			for(int n = 0; n<N; n++)
			{
				if(ans[n] == 0)
				{
					for(auto it: M)
					{
						if(it.first != A[n])
						{
							ans[n] = it.first;
							M[it.first]--;
							if(M[it.first] == 0)
								M.erase(it.first);
							break;
						}	
					}
				}
			}
			cout<<"Yes"<<endl;
			for(int n = 0; n<N; n++)
				cout<<ans[n]<<" ";
		}
		else
			cout<<"No";
		cout<<endl;
	}
	return 0;
}