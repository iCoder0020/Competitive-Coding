#include <bits/stdc++.h>

using namespace std;

#define int long long

bool inc(vector<int>&A, int N)
{
	for(int n = 0; n<N; n++)
		if(A[n]<n)
			return false;
	return true;
}

bool dec(vector<int>&A, int N)
{
	for(int n = 0; n<N; n++)
		if(A[n]<N-n-1)
			return false;
	return true;
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		if(inc(A, N) || dec(A, N))
			cout<<"Yes"<<endl;
		else
		{
			int i = 0, j = N-1;
			while(A[i]>=i)
				i++;
			i = (i==0)?0:(i-1);
			while(A[j]>=N-j-1)
				j--;
			j = (j==N-1)?N-1:(j+1);
			if((i>j && A[i]!=A[j]) || (i == j))
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
	return 0;
}
