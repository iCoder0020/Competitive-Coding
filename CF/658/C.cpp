#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		string A,B;
		cin>>A>>B;
		vector<int>v;
		for(int i = 0; i<N; i++)
		{
			if(i+1<N && A[i]!=B[i] && A[i+1]!=B[i+1])
			{
				v.push_back(i+1);
				v.push_back(1);
				v.push_back(i+1);
				i++;
			}
			else if(A[i]!=B[i])
			{
				v.push_back(i);
				if(i == 0)
					continue;
				v.push_back(0);
				v.push_back(i);
			}
		}
		cout<<v.size()<<" ";
		for(auto it:v)
			cout<<it+1<<" ";
		cout<<endl;
	}
	return 0;
}