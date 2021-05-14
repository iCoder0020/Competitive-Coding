#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int A[3];
		for(int n = 0; n<3; n++)
			cin>>A[n];
		sort(A, A+3);
		int ans = 0;
		for(int n = 2; n>=0; n--)
		{
			if(A[n] > 0)
			{
				A[n]--;
				ans++;
			}
		}
		for(int i = 2; i>=1; i--)
		{
			for(int j = i-1; j>=0; j--)
			{
				if(A[i] > 0 && A[j] > 0)
				{
					A[i]--;
					A[j]--;
					ans++;
				}
			}
		}
		if(A[0]>0 && A[1]>0 && A[2]>0)
			ans++;
		cout<<ans<<endl;
	}
	return 0;
}
