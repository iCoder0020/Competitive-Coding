/*
ID: iCoder0020
PROG: Valid BFS?
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int a,b;
	vector <vector<int>> T(N);
	vector <int> ::iterator it;
	queue <int> Q;
	for(int n = 0; n<N; n++)
	{
		cin>>a>>b;
		T(a-1).push_back(b-1);
		T(b-1).push_back(a-1);
	}
	for(int n = 0; n<N; n++)
	{
		cin>>a;
		Q.push(a-1);
		for(int m = 0; m<T(a-1).size(); m++)
		{
			cin>>b;
			Q.push(b-1);
			it = find (T(a-1), T(a-1).end(), b);
			if (it == T(a-1).end())
			{
				cout<<"No\n";
			}
		}
	}

	cout<<"Yes\n";
	return 0;
}