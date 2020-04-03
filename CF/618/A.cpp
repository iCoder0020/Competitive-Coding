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
		int A[N];
		int z = 0;
		int sum = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n] == 0)
			{
				z++;
				sum++;
			}
			sum += A[n];
		}
		if(sum!=0)
			cout<<z<<endl;
		else
			cout<<z+1<<endl;
	}
	return 0;
}
