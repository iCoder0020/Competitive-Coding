#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int A, M;
		cin>>A>>M;
		vector<int>divisors;
		for(int n = 1; n<=sqrt(M)+1; n++)
		{
			if(M%n == 0)
			{
				divisors.push_back(n);
				divisors.push_back(M/n);
			}
		}
		set<int>answers;
		for(auto d: divisors)
		{
			int k = M/d -1;
			if(k%A == 0 && k!=0)
			{
				k /= A;
				answers.insert(d*k);
			}
		}
		cout<<answers.size()<<endl;
		for(auto ans: answers)
			cout<<ans<<" ";
		cout<<endl;
	}
	return 0;
}