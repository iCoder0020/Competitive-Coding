/*
ID: ishansa2
PROG: sprime
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

ofstream fout("sprime.out");
ifstream fin("sprime.in");

#define int long long
#define INF 1LL<<32

vector<int>ans;
int N;

void solve(int x, int i)
{
	bool push = true;
	for(int j = 2; j*j<=x; j++)
	{
		if(x%j == 0)
		{
			push = false;
			break;
		}
	}
	if(!push)
		return;
	if(i == N)
	{
		ans.push_back(x);
		return;
	}
	for(int j = 1; j<=9; j+=2)
	{
		if(j == 5)
			continue;
		solve(x*10+j, i+1);
	}
}

int32_t main()
{
 	fin>>N;
 	vector<int>primes = {2,3,5,7};
 	for(auto it: primes)
 		solve(it, 1);
 	sort(ans.begin(), ans.end());
 	for(auto it: ans)
 		fout<<it<<endl;
    return 0;
}