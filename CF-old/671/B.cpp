#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int cnt = 0;
		int used = 0;
		for(int i = 1; i<32; i++)
		{
			int x = (1<<i)-1;
			int req = (x*(x+1))/2;
			if(used + req <= N)
			{
				cnt++;
				used += req;
			}
			else
				break;
		}
		cout<<cnt<<endl;
	}	
	return 0;
}
