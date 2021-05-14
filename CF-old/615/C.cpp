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
		vector<int> factors;
		for(int i = 2; i*i<=N; i++)
		{
			if(N%i == 0)
			{
				factors.push_back(i);
				if(i != N/i)
					factors.push_back(N/i);
			}
		}	
		if(factors.size() < 3)
			cout<<"NO"<<endl;
		else
		{
			sort(factors.begin(), factors.end());
			int m = factors.size();
			int a,b,c;
			int A = 1, B = 1, C = 1;
			for(int i = 0; i<m-2; i++)
			{
				a = factors[i];
				int x = N/a;
				for(int j = i+1; j<m-1; j++)
				{
					b = factors[j];
					if((x % b != 0) || (x/b <= 1))
						break;
					else
					{
						if(a != x/b && b != x/b)
						{
							c = x/b;
							A = a, B = b, C = c;
						}
					}
					if(A != B && A != C && B != C)
						break;
				}
				if(A != B && A != C && B != C)
					break;
			}

			if(C != 1)
				cout<<"YES"<<endl<<A<<" "<<B<<" "<<C<<" "<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}
