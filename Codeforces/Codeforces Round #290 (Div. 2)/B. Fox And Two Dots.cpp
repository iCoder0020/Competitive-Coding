/*
ID: iCoder0020
PROG: Fox And Two Dots
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,M;
	cin>>N>>M;
	vector<vector<char>>grid(N, vector<char>(M));
	for(int n = 0; n<N; n++)
		for(int m = 0; m<M; m++)
			cin>>grid[n][m];
	
	return 0;
}