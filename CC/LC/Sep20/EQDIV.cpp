#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int K;
	cin>>K;
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N]={0};
		int l = 0, r = pow(N,K);
		for(int n = 1; n<N; n++)
			l += pow(n,K);
		int L=1,H=N-1;
		while(l>r)
		{
			int x = (l-r)/2;
			if(x<=0)
				break;
			int lo = L, mid, hi = H;
			while(lo<hi)
			{
				mid = lo+(hi-lo)/2;
				if(pow(mid,K)<x)
					lo = mid+1;
				else
					hi = mid;
			}
			if(A[lo-1] == 1)
				break;
			A[lo-1] = 1;
			if(A[H-1] == 1)
				H--;
			l -= pow(lo,K);
			r += pow(lo,K);
		}
		A[N-1] = 1;
		cout<<abs(l-r)<<endl;
		for(int n = 0; n<N; n++)
			cout<<A[n];
		cout<<endl;
	}
	return 0;
}