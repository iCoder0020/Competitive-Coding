#include <bits/stdc++.h>

using namespace std;

#define int long long

int power(int a, int b)
{
	if(b == 1 || a == 1)
		return a;
	int c = power(a,b/2);
	if(b&1)
		return c*c*a;
	return c*c;
}

int32_t main()
{
	int K;
	cin>>K;
	int max_rep = 1;
	while(power(max_rep, 10)<K)
		max_rep++;
	string cf = "codeforces";
	int p = 1;
	string S = "";
	for(int n = 0; n<10; n++)
	{
		if(p*power(max_rep-1,10-n)>=K)
			max_rep--;
		for(int i = 0; i<max_rep; i++)
			S+=cf[n];
		p*=max_rep;
	}
	cout<<S<<endl;
	return 0;
}
