#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int num = 0;
	int den = N-2;
	for(int i = 2; i<N; i++)
	{
		int X = N;
		while(X)
		{
			num += X%i;
			X /= i;
		}
	}
	int g = __gcd(num, den);
	num /= g, den /= g;
	cout<<num<<"/"<<den<<endl;
	return 0;
}
