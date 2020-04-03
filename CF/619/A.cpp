#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string A,B,C;
		cin>>A>>B>>C;
		int N = A.length();
		char ch;
		for(int i = 0; i<N; i++)
		{
			if(C[i] == A[i])
			{
				ch = B[i];
				B[i] = C[i];
				C[i] = ch;
			}
			else if(C[i] == B[i])
			{
				ch = A[i];
				A[i] = C[i];
				C[i] = ch;
			}
			else
				A[i] = '%';
		}
		if(A == B)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
