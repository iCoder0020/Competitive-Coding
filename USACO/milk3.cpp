/*
ID: ishansa2
PROG: milk3
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1LL<<32

ofstream fout("milk3.out");
ifstream fin("milk3.in");

void rec(tuple<int,int,int>curr, tuple<int,int,int>&cap, set<tuple<int,int,int>>&vis, set<int>&c_values)
{
	int a[3];
	int A[3];
	tie(a[0], a[1], a[2]) =  curr;
	tie(A[0], A[1], A[2]) = cap;
	if(a[0] == 0)
		c_values.insert(a[2]);

	//i->j
	for(int i = 0; i<3; i++)
	{
		if(a[i] == 0)
			continue;
		for(int j = 0; j<3; j++)
		{
			if(i == j || a[j] == A[j])
				continue;
			int x = min(A[j], a[i]+a[j])-a[j];
			a[i] -= x;
			a[j] += x;
			tuple<int,int,int> T = make_tuple(a[0], a[1], a[2]);
			if(vis.find(T) == vis.end())
			{
				vis.insert(T);
				rec(T,cap,vis,c_values);
			}
			a[i] += x;
			a[j] -= x;
		}
	}
}

int32_t main()
{
 	int A,B,C;
 	fin>>A>>B>>C;
 	vector<int> c_values;
 	set<int>S;
 	tuple<int,int,int> milk, cap;
 	milk = make_tuple(0,0,C);
 	cap = make_tuple(A,B,C);
 	set<tuple<int,int,int>>vis;
 	vis.insert(milk);
 	rec(milk, cap, vis, S);
 	c_values = vector<int>(S.begin(), S.end());
 	// sort(c_values.begin(), c_values.end());
 	for(int i = 0; i<c_values.size(); i++)
 	{
 		fout<<c_values[i];
 		if(i != c_values.size()-1)
 			fout<<" ";
 	}
 	fout<<endl;
    return 0;
}