/*
ID: icoder_0020
PROG: Monk in the real estateMonk in the real estate
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
		int E;
		int count[10005] = {0};
		cin>>E;
		int X,Y;
		for(int e = 0; e<E; e++)
		{
			cin>>X>>Y;
			if(count[X] == 0)
			{
				count[X] = 1;
			}
			if(count[Y] == 0)
			{
				count[Y] = 1;
			}
		}
		int ans = 0;
		for(int n = 0; n<10005; n++)
		{
			ans += count[n];
		}
		cout<<ans<<endl;
	}
	return 0;
}