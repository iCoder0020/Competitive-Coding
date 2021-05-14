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
		char A[N][N];
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				cin>>A[i][j];
		bool poss = true;
		for(int i = N-1; i>=0; i--)
			for(int j = N-1; j>=0; j--)
				if(A[i][j] == '1' && i != N-1 && j != N-1 && A[i+1][j] == '0' && A[i][j+1] == '0')
					poss = false;
		if(poss)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
