/*
ID: iCoder0020
PROG: Array Triplets
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int N;
	int even;
	long int sum;
	for(int t = 0; t<T; t++)
	{
		sum = 0;
		even = 0;
		cin>>N;
		int A[N];
		vector <int> odd;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n]%2 == 0)
			{
				even++;
			}
			else
			{
				odd.push_back(A[n]);
			}
		}
		sort(odd.begin(), odd.end());
		for(int n = 0; n<odd.size(); n++)
		{
			if(n < odd.size()-1)
			{
				if(odd[n]+2 != odd[n+1])
				{
					sum += odd.size()-n;
				}
			}
		}
		sum += (even*(even-1))/2;
		cout<<sum<<"\n";
	}
	return 0;
}