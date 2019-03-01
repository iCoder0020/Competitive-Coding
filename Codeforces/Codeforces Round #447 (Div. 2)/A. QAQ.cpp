/*
ID: iCoder0020
PROG: QAQ
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;
	int N = S.length();
	int A[N] = {0};
	vector <int> index;
	for(int n = 0; n<N; n++)
	{
		if(S[n] == 'Q')
		{
			index.push_back(n);
		}
		if(n > 0)
		{
			A[n] += A[n-1];
		}
		if(S[n] == 'A')
		{
			A[n]++;
		}
	}
	int sum = 0;
	while(index.size() > 1)
	{
		auto it1 = index.begin();
		for(auto it2 = it1+1; it2!=index.end(); it2++)
		{
			int i = *it1;
			int j = *it2;
			sum += A[j-1] - A[i];
		}
		index.erase(it1);
	}
	cout<<sum<<endl;
	return 0;
}