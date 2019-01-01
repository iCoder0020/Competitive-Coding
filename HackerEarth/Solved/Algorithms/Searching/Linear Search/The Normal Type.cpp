/*
ID: icoder_0020
PROG: The Normal Type
LANG: C++                  
*/

#include <bits/stdc++.h>
 
typedef long long int li;

using namespace std;

int main()
{
	int N;
	cin>>N;
	map<int, li> M;
	int x;
	for(int n = 0; n<N; n++)
	{
		cin>>x;
		auto it = M.find(x);
		if(it == M.end())
		{
			M[x] = 1;
		}
		else
		{
			M[x]++;
		}
	}
	return 0;
}
