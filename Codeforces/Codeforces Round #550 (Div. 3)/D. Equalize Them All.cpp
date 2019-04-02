/*
ID: iCoder0020
PROG: Equalize Them All
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long 

#define n_max 200005

using namespace std;



int32_t main()
{
	int N;
	cin>>N;
	int count[n_max] = {0};
	int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		count[A[n]]++;
	}
	int max_freq = 0;
	int max_freq_num;
	for(int n = 0; n<n_max; n++)
	{
		if(count[n] > max_freq)
		{
			max_freq = count[n];
			max_freq_num = n;
		}
	}
	cout<<N-max_freq<<endl;
	int index = -1;
	for(int n = 0; n<N; n++)
	{
		if(A[n] == max_freq_num)
		{
			index = n;
			break;
		}
	}
	int zero = 0;
	for(int n = max(zero, index-1); n>=0; n--)
	{
		if(A[n] != max_freq_num)
		{
			int code = (A[n]>max_freq_num)?2:1;
			if(code == 1)
				cout<<code<<" "<<n+1<<" "<<n+2<<endl;
			else
				cout<<code<<" "<<n+1<<" "<<n+2<<endl;
		}
	}
	for(int n = min(index+1, N-1); n<N; n++)
	{
		if(A[n] != max_freq_num)
		{
			int code = (A[n]>max_freq_num)?2:1;
			if(code == 1)
				cout<<code<<" "<<n+1<<" "<<n<<endl;
			else
				cout<<code<<" "<<n+1<<" "<<n<<endl;
		}
	}
	return 0;
}