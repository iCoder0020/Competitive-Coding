#include <bits/stdc++.h>

using namespace std;

#define int long long

int P,F,cntS,cntW,wtS,wtW;

bool bs(int N)
{
	for(int n = 0; n<=cntS; n++)
	{
		int s = n;
		int w = N-s;
		if(w>cntW)
		{
			n+=(w-cntW)-1;
			continue;
		}
		for(int i = 0; i<=s; i++)
		{
			int ps = i;
			int fs = s-i;
			int pr = P-ps*wtS;
			int fr = F-fs*wtS;
			if(pr<0)
				break;
			if(fr<0)
			{
				i=(s+F/wtS)-5;
				continue;
			}
			int a = pr/wtW;
			int b = fr/wtW;
			if(a+b>=w)
				return true;
		}
	}
	return false;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		cin>>P>>F>>cntS>>cntW>>wtS>>wtW;
		int lo = 0, mid, hi = cntS+cntW;
		while(lo<hi)
		{
			mid = lo + (hi-lo+1)/2;
			if(bs(mid))
				lo = mid;
			else
				hi = mid-1;
		}
		cout<<lo<<endl;
	}
	return 0;
}
