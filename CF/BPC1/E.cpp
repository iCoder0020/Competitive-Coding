#include <bits/stdc++.h>

using namespace std;

#define int long long

int query(int x, int N)
{
	int a,b;
	cout<<"? "<<x<<endl;
	fflush(stdout);
	cin>>a;

	cout<<"? "<<x+N/2<<endl;
	fflush(stdout);
	cin>>b;

	return a-b;
}

int32_t main()
{
	int N;
	cin>>N;
	int x = -1;
	bool found = false;
	int init = query(1, N);
	if(init == 0)
	{
		found = true;
		x = 1;
	}
	if(abs(init)%2 == 1)
		found = true;
	if(!found)
	{
		int lo = 2, mid, hi = N/2;
		while(lo<hi)
		{
			mid = lo + (hi-lo+1)/2;
			int d = query(mid, N);
			if(d == 0)
			{
				x = mid;
				found = true;
				break;
			}
			if(d*init>0)
				lo = mid;
			else
				hi = mid-1;
		}
	}
	cout<<"! "<<x<<endl;
	return 0;
}
