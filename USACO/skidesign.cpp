/*
ID: ishansa2
PROG: skidesign
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1LL<<32

ofstream fout("skidesign.out");
ifstream fin("skidesign.in");

int sq(int x)
{
	return x*x;
}

int32_t main()
{
 	int N;

 	fin>>N;
 	int A[N];
 	for(int n = 0; n<N; n++)
 		fin>>A[n];
 	sort(A,A+N);
 	int ans;
 	int minm = INF;
 	for(int i = 0; i<=83; i++)
 	{
 		ans = 0;
 		for(int j = 0; j<N; j++)
 		{
 			if(A[j]>i+17)
 				ans += sq(A[j]-i-17);
 			else if(A[j]<i)
 				ans += sq(A[j]-i);
 		}
 		minm = min(ans, minm);
 	}
 	fout<<minm<<endl;
    return 0;
}