#include <bits/stdc++.h>

using namespace std;

#define int long long

int f(int x)
{
	int y = 0;
	while(x)
	{
		y += x%10;
		x/=10;
	}
	return y;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N], B[N];
		int a = 0, b = 0;
		for(int n = 0; n<N; n++)
		{	
			int x,y;
			cin>>x>>y;		
			A[n] = f(x),  B[n] = f(y);
		}
		for(int n = 0; n<N; n++)
		{
			if(A[n]>=B[n])
				a++;
			if(B[n]>=A[n])
				b++;
		}
		if(a>b)
			cout<<0<<" "<<a;
		else if(b>a)
			cout<<1<<" "<<b;
		else
			cout<<2<<" "<<a;
		cout<<endl;
	}
	return 0;
}