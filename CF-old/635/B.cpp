#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,A,B;
		cin>>N>>A>>B;
		int aleft = A;
		int bleft = B;
		bool poss = false;
		while(1)
		{
			// cout<<aleft<<" "<<bleft<<" "<<N<<endl;
			if(N<=0)
			{
				poss = true;
				break;
			}
			if(aleft == 0 && bleft == 0)
				break;
			if(aleft == 0)
			{
				N -= bleft*10;
				bleft = 0;
				continue;
			}
			if(bleft == 0)
			{
				while(aleft)
				{
					N = N/2 + 10;
					aleft--;
				}
				continue;
			}
			if(N>=40 || N>bleft*10)
			{
				aleft--;
				N = N/2+10;
			}
			else
			{
				bleft--;
				N -= 10;
			}
		}
		if(poss)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
