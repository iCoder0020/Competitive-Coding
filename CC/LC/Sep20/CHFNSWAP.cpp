#include <bits/stdc++.h>

using namespace std;

#define int long long
#define psum(x) (full_sum-(x*(x+1)))/2

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int full_sum = (N*(N+1))/2;
		int ans = 0;
		if(N>2 && (full_sum%2)==0)
		{
			int lo, mid, hi;
			lo = 1, hi = N;
			while(lo<hi)
			{
				mid = lo + (hi-lo)/2;
				if(psum(mid) <= N-1)
					hi = mid;
				else
					lo = mid+1;
			}
			while(psum(lo)>=1 && psum(lo)<=N-1)
			{
				ans+=min({psum(lo), N-psum(lo), N-lo});
				lo++;
			}
			if(psum(lo) == 0)
				ans += (lo*(lo-1))/2 + ((N-lo)*(N-lo-1))/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}