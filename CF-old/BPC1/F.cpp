#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007
#define MAX 1000005

int32_t main()
{
	string S;
	cin>>S;
	int N = S.length();
	vector<int>pow2(MAX, 1);
	for(int i = 1; i<MAX; i++)
		pow2[i] = (2*pow2[i-1])%MOD;
	int ans = 0;
	int k = 0;
	int b_count = 0;
	for(int n = N-1; n>=0;)
	{
		int j = n;
		while(j>=0 && S[j] == 'a')
			j--;
		int i = j;
		int a = 0, b = 0;
		while(i>=0 && S[i] == 'b')
		{
			b++;
			i--;
		}
		while(i>=0 && S[i] == 'a')
		{
			a++;
			i--;
		}
		// cout<<a<<" "<<b+b_count<<endl;
		ans = (ans + (((pow2[a]-1+MOD)%MOD) * (b+b_count)%MOD)%MOD)%MOD;
		n = i;
		b_count = (pow2[a]*(b+b_count))%MOD;
	}
	cout<<ans<<endl;
	return 0;
}
