/*
ID: iCoder0020
PROG: Maxim and Biology
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int min_off(char a, char b)
{
	return min(abs(b-a), min(abs(b-a+26), abs(a-b+26)));
}

int32_t main()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	string word = "ACTG";
	int cnt;
	int min_cnt = INT_MAX;
	for(int n = 0; n<=N-4; n++)
	{
		cnt = 0;
		for(int m = 0; m<4; m++)
		{
			cnt+=min_off(S[n+m], word[m]);
		}
		min_cnt = min(cnt, min_cnt);
	}
	cout<<min_cnt<<endl;
	return 0;
}