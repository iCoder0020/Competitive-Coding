#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pos(i,t) (60*i+(V[i]*(t)))

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
		int V[N];
		bool infected[N];
		for(int n = 0; n<N; n++)
			cin>>V[n];
		int min_cnt = N+1;
		int max_cnt = 0;
		for(int runner = 0; runner<N; runner++)
		{	
			int max_speed = runner;
			int min_speed = runner;
			for(int n = 0; n<N; n++)
				infected[n] = false;
			infected[runner] = true;
			for(int n = 0; n<runner; n++)
			{
				if(V[n]>V[runner])
				{
					infected[n] = true;
					if(V[n]>V[max_speed])
						max_speed = n;
				}
			}
			for(int n = runner+1; n<N; n++)
			{
				if(V[n]<V[max_speed])
					infected[n] = true;
				if(V[n]<V[min_speed])
					min_speed = n;
			}
			for(int n = 0; n<runner; n++)
			{
				if(V[n]>V[min_speed])
					infected[n] = true;
			}
			int cnt = 0;
			for(int n = 0; n<N; n++)
				if(infected[n])
					cnt++;
			// cout<<cnt<<" ";
			min_cnt = min(cnt, min_cnt);
			max_cnt = max(cnt, max_cnt);
		}
		cout<<min_cnt<<" "<<max_cnt;
		cout<<endl;
	}
	return 0;
}