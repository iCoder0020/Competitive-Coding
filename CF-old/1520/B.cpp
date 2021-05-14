#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	vector<int> A(81);
	for(int i = 0; i<9; i++)
		A[i] = i+1;
	for(int i = 9; i<81; i++)
		A[i] = A[i-9]*10 + A[i%9];
	while(T--)
	{
		int N;
		cin>>N;
		int ans = -1;
		for(int i = 80; i>=0; i--)
		{
			if(A[i]<=N)
			{
				ans = i+1;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
