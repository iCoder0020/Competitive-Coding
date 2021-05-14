#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,K1,K2;
		cin>>N>>K1>>K2;
		int A[K1], B[K2];
		int maxa = -1, maxb = -1;
		for(int i = 0; i<K1; i++)
		{
			cin>>A[i];
			maxa = max(maxa, A[i]);
		}

		for(int i = 0; i<K2; i++)
		{
			cin>>B[i];
			maxb = max(maxb, B[i]);
		}
		if(maxa > maxb)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
