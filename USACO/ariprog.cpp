/*
ID: ishansa2
PROG: ariprog
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1LL<<32

ofstream fout("ariprog.out");
ifstream fin("ariprog.in");

int N,M;
vector<bool>is_there;
vector<int>cand;
bool ans;

void search(int d)
{
	if(d>(2*M*M/(N-1)))
		return;
	for(auto a: cand)
	{
		if(a + (N-1)*d > 2*M*M)
		{
			search(d+1);
			return;
		}
		bool poss = true;
		for(int n = 0; n<N; n++)
		{
			if(!is_there[a+n*d])
			{
				poss = false;
				break;
			}
		}
		if(poss)
		{
			ans = true;
			fout<<a<<" "<<d<<endl;
		}
	}
}

int32_t main()
{
 	fin>>N>>M;
 	is_there.resize(2*M*M+1, false);
 	set<int>S;
 	for(int p = 0; p<=M; p++)
 		for(int q = 0; q<=M; q++)
 		{
 			is_there[p*p+q*q] = true;
 			S.insert(p*p+q*q);
 		}
 	cand = vector<int>(S.begin(), S.end());
 	sort(cand.begin(), cand.end());
 	ans = false;

 	search(1);

 	if(!ans)
 		fout<<"NONE"<<endl;
    return 0;
}