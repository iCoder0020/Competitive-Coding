#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N];
		int cnt0 = 0, cnt1 = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n] == 0)
				cnt0++;
			else
				cnt1++;
		}
		int k = N/2;
		if(k&1)
		{
			if(cnt0 == cnt1)
			{
				cout<<k<<endl;
				for(int n = 0; n<k; n++)
					cout<<0<<" ";
			}
			else
			{
				cout<<k+1<<endl;
				for(int n = 0; n<k+1; n++)
				{
					if(cnt0>cnt1)
						cout<<0<<" ";
					else if(cnt1>cnt0)
						cout<<1<<" ";
				}
			}
			cout<<endl;
			
		}
		else
		{
			cout<<k<<endl;
			for(int n = 0; n<k; n++)
			{
				if(cnt0>=cnt1)
					cout<<0<<" ";
				else
					cout<<1<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
