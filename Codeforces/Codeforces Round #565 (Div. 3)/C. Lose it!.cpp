/*
ID: iCoder0020
PROG: Lose it!
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	int good[] = {4,8,15,16,23,42};
	vector<int>i(6, 0);
	int cnt = 0;
	bool stop = false;
	for(int n = 0; n<N; n++)
		cin>>A[n];
	while(!stop)
	{
		for(int n = 0; n<6; n++)
		{
			if(n == 0)
			{
				while(i[n]<N && A[i[n]] != good[n])
					i[n]++;
			}
			else
			{
				while(i[n]<N && (A[i[n]] != good[n] || i[n-1] >= i[n]))
					i[n]++;	
			}
			if(i[n]>=N)
			{
				stop = true;
				break;
			}
			if(n == 5)
			{
				for(int m = 0; m<6; m++)
					i[m]++;
				cnt++;
			}
		}
	}
	cout<<N-(cnt*6)<<endl;
	return 0; 
}