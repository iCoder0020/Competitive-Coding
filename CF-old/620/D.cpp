#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		string S;
		cin>>S;
		vector<int> arr(N, 0);
		int minm = 0;
		for(int n = 0; n<N-1; n++)	
		{
			if(S[n] == '<')
				arr[n+1] = arr[n]+1;
			else
				arr[n+1] = arr[n]-1;
			minm = min(minm, arr[n+1]);
		}
		for(auto &it: arr)
			it += abs(minm)+1;
		for(auto it: arr)
			cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
