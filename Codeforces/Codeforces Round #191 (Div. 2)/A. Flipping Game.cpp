/*
ID: iCoder0020
PROG: Flipping Game
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int get_answer(vector<int> A, int i, int j)
{
	int N = A.size();
	int max_count = 0;
	for(int n = i; n<=j; n++)
	{
		A[n] = 1-A[n];
	}
	for(int n = 0; n<N; n++)
		if(A[n] == 1)
			max_count++;
	// cout<<i<<" "<<j<<" "<<max_count<<endl;
	return max_count;
}

int main()
{
	int N;
	cin>>N;
	vector<int> A(N);
	int count = 0;
	int max_count = 0;
	for(int n = 0; n<N; n++)
		cin>>A[n];
	for(int i = 0; i<N; i++)
	{
		for(int j = i; j<N; j++)
		{
			count = get_answer(A, i, j);
			max_count = max(count, max_count);
		}
	}
	cout<<max_count<<endl;
	return 0;
}