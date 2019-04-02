/*
ID: ishan_sang
PROG: SONGSHOP
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,M,P;
	cin>>N>>M>>P;
	int album[N], song_price[N], value[N], album_price[M];
	int total_value = 0;
	for(int n = 0; n<N; n++)
		cin>>album[n]>>song_price[n]>>value[n];
	for(int m = 0; m<M; m++)
		cin>>album_price[m];
	
	return 0;
}