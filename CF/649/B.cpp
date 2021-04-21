#include <bits/stdc++.h>

using namespace std;

#define int long long

bool sign(int x)
{
	if(x<0)
		return false;
	return true;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N];
		vector<int>v;
		for(int n = 0; n<N; n++)
			cin>>A[n];
		bool B[N];
		B[0] = true;
		B[1] = true;
		int i = 0;
		for(int n = 2; n<N; n++)
		{
			if(sign(A[n] - A[n-1]) == sign(A[n-1] - A[i]))
			{
				B[n-1] = false;
				B[n] = true;
			}
			else
			{
				i = n-1;
				B[n] = true;
			}
		}
		for(int n = 0; n<N; n++)
			if(B[n])
				v.push_back(A[n]);
		cout<<v.size()<<endl;
		for(auto it: v)
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
