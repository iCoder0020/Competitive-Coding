/*
ID: ishan_sang
PROG: GARGOYLE
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	char ch;
	vector <set<int>> S (N);
	set <int> visited;
	for(int n = 0; n<N; n++)
	{
		for(int m = 0; m<N; m++)
		{
			cin>>ch;
			if(ch == 'T')
			{
				S[n].insert(m);
			}
		}
	}
	int max = 0;
	for(int n = 0; n<N; n++)
	{
		if(visited.find(n) == visited.end())
		{
			int num = 0;
			for(auto it = S[n].begin(); it!=S[n].end(); it++)
			{
				if(S[n] == S[*it])
				{
					num++;
					visited.insert(*it);
				}
				else
				{
					num = 0;
					break;
				}
			}
			if(num > max)
			{
				max = num;
			}
			if(max == N)
			{
				break;
			}
		}
	}
	cout<<max<<endl;
	return 0;
}