#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	char arr[4] = {'a','b','c','d'};
	for(int n = 0; n<N; n++)
		cout<<arr[n%4];
	cout<<endl;
	return 0;
}
