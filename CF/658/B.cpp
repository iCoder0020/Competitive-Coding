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
		int A[N];
		int ones = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n] == 1)
				ones++;
			else
				A[n]=2;
		}
		if(ones == 0)
			cout<<"First"<<endl;
		else
		{
			int chance = 0;
			for(int n = 0; n<N;)
			{
				// cout<<n<<" "<<chance<<endl;
				if(n == N-1 || A[n]!=1)
					break;
				if(A[n] == 1)
					n++, chance^=1;
				else if(A[n]!=1 && A[n+1]!=1)
					n++;
				else if(A[n]!=1 && A[n+1]==1)
				{
					if(A[n]&1 == 0)
						chance^=1;
					n++;
				}

			}
			if(chance == 0)
				cout<<"First";
			else
				cout<<"Second";
			cout<<endl;
		}

	}
	return 0;
}
