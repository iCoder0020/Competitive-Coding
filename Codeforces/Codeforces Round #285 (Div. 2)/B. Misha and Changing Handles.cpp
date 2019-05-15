/*
ID: iCoder0020
PROG: Misha and Changing Handles
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

map<string,string>rep;
map<string,int>sz;

void make_set(string x)
{
	rep[x] = x;
	sz[x] = 1;
}

string find_set(string x)
{
	while(rep[x] != x)
	{
		rep[x] = rep[rep[x]];
		x = rep[x];
	}
	return x;
}

void union_set(string x, string y)
{
	string a = find_set(x);
	string b = find_set(y);

	if(a!=b)
		rep[x] = y;
}

int32_t main()
{
	int Q;
	cin>>Q;
	rep.clear();
	sz.clear();
	set<string>S;
	set<string>ans;
	while(Q--)
	{
		string A,B;
		cin>>A>>B;
		auto it1 = S.find(A);
		auto it2 = S.find(B);
		if(it1 == S.end() && it2 == S.end())
		{
			S.insert(A);
			S.insert(B);
			ans.insert(A);
			make_set(A);
			make_set(B);
		}
		else
		{
			S.insert(B);
			make_set(B);
		}
		union_set(A,B);
	}	
	cout<<ans.size()<<endl;
	for(auto it: ans)
		cout<<it<<" "<<find_set(it)<<endl;
	return 0;
}