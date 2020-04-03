/*
ID: ishansa2
PROG: numtri
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

ofstream fout("numtri.out");
ifstream fin("numtri.in");

#define int long long
#define INF 1LL<<32

int solve(vector<vector<int>>&A, int i, int j, vector<vector<int>>&ans)
{
	if(i == A.size())
		return 0;
	if(ans[i][j] != -1)
		return ans[i][j];
	ans[i][j] = A[i][j] + max(solve(A,i+1,j,ans), solve(A,i+1,j+1,ans));
	return ans[i][j];
}

int32_t main()
{
 	int N;
 	fin>>N;
 	vector<vector<int>>A(N);
 	vector<vector<int>>ans(N);
 	for(int i = 0; i<N; i++)
 	{
 		vector<int>v(i+1);
 		for(int j = 0; j<=i; j++)
 			fin>>v[j];
 		A[i] = v;
 		vector<int>().swap(v);
 		vector<int>y(i+1, -1);
 		ans[i] = y;
 		vector<int>().swap(y);
 	}
 	fout<<solve(A, 0, 0, ans)<<endl;
    return 0;
}