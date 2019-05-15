/*
ID: iCoder0020
PROG: Long Number
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	int f[10];
	for(int i = 1; i<=9; i++)
		cin>>f[i];
	int index = -1;
	for(int i = 0; i<N; i++)
	{
		int num = S[i]-'0';
		if(f[num] > num)
		{
			index = i;
			break;
		}
	}
	if(index != -1)
	{
		for(int i = index; i<N; i++)
		{
			int num = S[i]-'0';
			if(f[num] < num)
				break;
			else
				S[i] = f[num]+'0';
		}
	}
	cout<<S<<endl;
	return 0;
}