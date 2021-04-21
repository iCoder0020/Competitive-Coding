#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		vector<int>odd;
		vector<int>even;
		for(int n = 0; n<2*N; n++)
		{
			int x;
			cin>>x;
			if(x&1)
				odd.push_back(n+1);
			else
				even.push_back(n+1);
		}
		if(odd.size()&1)
		{
			odd.pop_back();
			even.pop_back();
		}
		else
		{
			if(odd.size()>=2)
			{
				odd.pop_back();
				odd.pop_back();
			}
			else
			{
				even.pop_back();
				even.pop_back();
			}
		}
		for(int n = 0; n<odd.size(); n+=2)
			cout<<odd[n]<<" "<<odd[n+1]<<endl;
		for(int n = 0; n<even.size(); n+=2)
			cout<<even[n]<<" "<<even[n+1]<<endl;
	}
	return 0;
}
