/*
ID: iCoder0020
PROG: Vus the Cossack and Numbers
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	double arr[N];
	int ans[N];
	vector<bool>poss (N, true);
	int sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>arr[n];
		if(ceil(arr[n]) == floor(arr[n]))
			poss[n] = false;
		ans[n] = arr[n];
		sum += ans[n];	
	}
	int n = 0;
	while(sum > 0)
	{
		if(poss[n] && arr[n]<0)
		{
			ans[n]--;
			sum--;
		}
		n++;
	}
	while(sum < 0)
	{
		if(poss[n] && arr[n]>0)
		{
			ans[n]++;
			sum++;
		}
		n++;
	}
	for(int n = 0; n<N; n++)
		cout<<ans[n]<<" ";
	cout<<endl;
	return 0; 
}