/*
ID: iCoder0020
PROG: Average Superhero Gang Power
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;
typedef long double ld;

using namespace std;

int main()
{
	li N,K,M;
	cin>>N>>K>>M;
	li A[N];
	ld av_power = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	sort(A, A+N);
	li B[N];
	B[0] = A[0];
	for(int n = 1; n<N; n++)
	{
		B[n] = B[n-1] + A[n];
	}
	ld max_av_power = (ld)B[N-1]/N;
	for(int m = 0; m<=min(M,N-1); m++)
	{
		av_power = (ld)((B[N-1] - B[m] + A[m]) + min(K*(N-m),M-m))/(N-m);
		max_av_power = max(av_power, max_av_power);
	}
	cout<<setprecision(15)<<fixed<<max_av_power<<endl;
	return 0;
}