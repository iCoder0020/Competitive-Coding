#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int powmod(int a, int b, int c)
{
	if(a == 1 || b == 0)
		return 1;
	if(b == 1)
		return a;
	int d = powmod(a,b/2,c);
	if(b&1)
		return (a*((d*d)%MOD))%MOD;
	return (d*d)%MOD;
}

int32_t main()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	map<char,int>MAP;
	for(auto it: S)
		MAP[it]++;
	vector<int>a(4);
	a[0] = MAP['A'];
	a[1] = MAP['G'];
	a[2] = MAP['C'];
	a[3] = MAP['T'];
	sort(a.begin(), a.end(), greater<int>());
	int cnt = 1;
	for(int i = 1; i<4; i++)
	{
		if(a[i] == a[i-1])
			cnt++;
		else
			break;
	}
	cout<<powmod(cnt,N,MOD)<<endl;
	return 0;
}
