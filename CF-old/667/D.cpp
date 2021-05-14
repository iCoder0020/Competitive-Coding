#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,S;
		cin>>N>>S;
		vector<int>v;
		int sum = 0;
		int Nc = N;
		while(N)
		{
			int x = N%10;
			sum += x;
			v.push_back(x);
			N /= 10;
		}
		v.push_back(0);
		reverse(v.begin(), v.end());
		if(sum<=S)
			cout<<0;
		else
		{
			for(int n = v.size()-1; n>=1; n--)
			{
				sum -= v[n];
				v[n] = 0;
				sum++;
				v[n-1]++;
				if(sum<=S)
					break;
			}
			int M = 0;
			for(int n = 0; n<v.size(); n++)
				M = M*10 + v[n];
			cout<<M-Nc;
		}
		cout<<endl;
	}
	return 0;
}