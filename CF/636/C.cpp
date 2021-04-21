#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int old_sign = (A[0]>0)?0:1;
		int new_sign;
		int sum = A[0];
		int prev = A[0];
		for(int i = 1; i<N; i++)
		{
			new_sign = (A[i]>0)?0:1;
			if(old_sign == new_sign)
			{
				if(A[i]>prev)
				{
					sum += (A[i]-prev);
					prev = A[i];
				}
				// cout<<sum<<endl;
				continue;
			}
			old_sign = new_sign;
			sum += A[i];
			prev = A[i];
			// cout<<sum<<endl;
		}
		cout<<sum<<endl;
	}
	return 0;
}
