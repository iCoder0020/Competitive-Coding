/*
ID: ishan_sang
PROG: CHFPARTY
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int N;
	int people;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		people = 0;
		sort(A, A+N);
		for(int n = 0; n<N; n++)
		{
			if(A[n] <= people)
			{
				people++;
			}
		}
		cout<<people<<endl;
	}
	return 0;
}