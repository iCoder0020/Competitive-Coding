#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	
	int N,M,K;
	cin>>N>>M>>K;
	int x,y;
	for(int k = 0; k<2*K; k++)
		cin>>x>>y;
	string S = "";
	for(int n = 0; n<N-1; n++)
		S += 'U';
	for(int m = 0; m<M-1; m++)
		S += 'L';
	for(int i = 0; i<N; i++)
	{
		char c = (i%2 == 0)?'R':'L';
		for(int j = 0; j<M-1; j++)
			S += c;
		if(i != N-1)
			S += 'D';
	}
	cout<<S.size()<<endl;
	cout<<S<<endl;
	return 0;
}
