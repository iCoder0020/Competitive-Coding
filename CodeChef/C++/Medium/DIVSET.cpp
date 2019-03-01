/*
ID: ishan_sang
PROG: DIVSET
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		li N,K,C;
		cin>>N>>K>>C;
		li temp;
		multiset<li>M;
		for(li n = 0; n<N; n++)
		{
			cin>>temp;
			M.insert(temp);
		}
		li steps = 0;
		bool possible = true;
		while(M.size() >= K && possible)
		{
			auto it = M.begin();
			li num;
			for(li i = 0; i<K; i++)
			{
				if(i == 0)
				{
					num = *it;
				}
				else
				{
					it = lower_bound(M.begin(), M.end(), C*num);
					if(it == M.end())
					{
						possible = false;
						break;
					}
					else
					{
						num = *it;
					}
				}
				M.erase(it);
				if(i == K-1)
				{
					steps++;
				}
			}	
		}
		cout<<steps<<endl;
	}
	return 0;
}