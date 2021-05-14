#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e13

int cost(vector<int>&A, int c)
{
	int x = 0;
	int powC = 1;
	for(int n = 0; n<A.size(); n++)
	{
		if(x>INF|| powC>INF)
		{
			x = INF;
			break;
		}
		x += abs(A[n]-powC);
		powC = c*powC;
	}
	return x;
}

int32_t main()
{
	int N;
	cin>>N;
	vector<int>A(N);
	for(int n = 0; n<N; n++)
		cin>>A[n];
	sort(A.begin(), A.end());
	int lo = 1, mid, hi = 1e5;
	while(lo<hi)
	{
		mid = lo + (hi-lo)/2;
		// cout<<mid<<" "<<cost(A,mid)<<endl;
		if(cost(A, mid) <= cost(A, mid-1) && cost(A, mid) <= cost(A, mid+1))
		{
			if(cost(A,mid)!=INF)
				break;
			else
				hi = mid;
		}
		if(cost(A, mid) > cost(A, mid-1))
			hi = mid;
		if(cost(A, mid) > cost(A, mid+1))
			lo = mid;
	}
	cout<<cost(A,mid)<<endl;
	return 0;
}
