/*
ID: iCoder0020
PROG: Good Array
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	vector <pair<int,int>> A;
	long long int sum = 0;
	int temp;
	for(int n = 0; n<N; n++)
	{
		cin>>temp;
		sum += temp;
		A.push_back(make_pair(temp, n));
	}
	vector <int> index;
	sort(A.begin(), A.end());
	for(int n = 0; n<N; n++)
	{
		sum -= A[n].first;
		if(n == N-1)
		{
			if(sum == 2*A[N-2].first)
			{
				index.push_back(A[n].second+1);
			}
		}
		else
		{
			if(sum == 2*A[N-1].first)
			{
				index.push_back(A[n].second+1);
			}
		}
		sum += A[n].first;
	}	
	cout<<index.size()<<endl;
	for(int n = 0; n<index.size(); n++)
	{
		cout<<index[n]<<" ";
	}
	cout<<endl;
	return 0;
}