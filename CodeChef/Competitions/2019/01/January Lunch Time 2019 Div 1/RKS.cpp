/*
ID: ishan_sang
PROG: RKS
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;	
	for(int t = 0; t<T; t++)
	{
		int N;
		cin>>N;
		int K;
		cin>>K;
		int P = N-K;
		int row[N] = {0};
		int col[N] = {0};
		int x,y;
		for(int k = 0; k<K; k++)
		{
			cin>>x>>y;
			row[x-1] = 1;
			col[y-1] = 1;
		}
		pair<int,int> pos[P];
		int cnt = 0;
		for(int p = 0; p<P; p++)
		{
			while(row[cnt] == 1)
			{
				cnt++;
			}
			pos[p].first = cnt+1;
			row[cnt] = 1;
			cnt++;
		}
		
		cnt = 0;
		for(int p = 0; p<P; p++)
		{
			while(col[cnt] == 1)
			{
				cnt++;
			}
			pos[p].second = cnt+1;
			col[cnt] = 1;
			cnt++;
		}
		cout<<P<<" ";
		for(int p =0; p<P; p++)
		{
			cout<<pos[p].first<<" "<<pos[p].second<<" ";
		}
		cout<<endl;
	}
	return 0;
}