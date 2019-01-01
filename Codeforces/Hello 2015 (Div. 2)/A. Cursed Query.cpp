/*
ID: iCoder0020
PROG: Cursed Query
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N,Q;
	cin>>N>>Q;
	li temp;
	li sum[N];
	for(int n = 0; n<N; n++)
	{
		cin>>temp;
		if(n == 0)
		{
			sum[n] = temp;
		}
		else
		{
			sum[n] = sum[n-1]+temp;
		}
	}
	li time;
	int min, max, mid;
	for(int q = 0; q<Q; q++)
	{
		cin>>time;
		if(N == 1)
		{
			cout<<1<<endl;
		}
		else
		{
			time = time%sum[N-1];
			if(time<sum[0])
			{
				cout<<1<<endl;
				continue;
			}
			if(time>=sum[N-2] && time<sum[N-1])
			{
				cout<<N<<endl;
				continue;
			}
			min = 0;
			max = N-1;
			while(min<=max)
			{
				mid = (min+max)/2;
				if(mid>0)
				{
					if(time>=sum[mid-1] && time<sum[mid])
					{
						cout<<mid+1<<endl;
						break;
					}
				}
				if(mid<N)
				{
					if(time>=sum[mid] && time<sum[mid+1])
					{
						cout<<mid+2<<endl;
						break;
					}
				}
				if(time<sum[mid])
				{
					max = mid - 1;
				}
				else if(time>sum[mid])
				{
					min = mid + 1;
				}
				else
				{
					cout<<mid+2<<endl;
					break;
				}
			}
		}
	}
	return 0;
}