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
		int A[N], B[N];
		vector<int>next;
		int cnt = ((N+1)*N)/2;
		int c = 1;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			A[n] = abs(A[n]);
			if(A[n]%2 != 0)
			{
				if(A[n] == 0)
					next.push_back(n);
				B[n] = 0;
			}
			else if(A[n]%4 == 0)
			{
				B[n] = 2;
				next.push_back(n);
			}
			else
			{
				B[n] = 1;
				next.push_back(n);
			}
		}
		int i = 1;
		next.push_back(N);
		next.push_back(N);
		for(int n = 0; n<N; n++)
		{
			// cout<<B[n]<<" ";
			while(next[i]<=n)
				i++;
			if(B[n] == 2)
			{
				c = 1;
				continue;
			}
			else if(B[n] == 1)
			{
				// cout<<next[i]<<" "<<n<<endl;
				cnt -= c*(next[i]-n);
				c = 1;
			}
			else
				c++;
			// cout<<cnt<<endl;
		}
		cout<<cnt<<endl;
	}
	return 0;
}