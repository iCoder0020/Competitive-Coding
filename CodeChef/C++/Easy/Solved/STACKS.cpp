/*
ID: ishan_sang
PROG: STACKS
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
		int stack[N];
		for(int n = 0; n<N; n++)
		{
			cin>>stack[n];
		}
		multiset <int> ans;
		for(int i = 0; i<N; i++)
		{
			int element = stack[i];
			auto it = ans.upper_bound(element);
			if(it == ans.end())
			{
				ans.insert(element);
			}
			else
			{
				ans.erase(it);
				ans.insert(element);
			}
		}		
		cout<<ans.size()<<" ";
		for(auto it: ans)
		{
			cout<<it<<" ";
		}
		cout<<endl;
	}
	return 0;
}