#include <bits/stdc++.h>

using namespace std;

#define int long long

int num_digits(int x)
{
	int cnt = 0;
	while(x)
	{
		x/=10;
		cnt++;
	}
	return cnt;
}

int32_t main()
{
	int TC;
	cin>>TC;
	int pow2[50];
	int pow3[50];
	int pow10[50];
	pow2[0] = 1;
	pow3[0] = 1;
	pow10[0] = 1;
	for(int n = 1; n<50; n++)
	{
		pow2[n] = 2*pow2[n-1];
		pow3[n] = 3*pow3[n-1];
		pow10[n] = 10*pow10[n-1];
	}
	while(TC--)
	{
		int A,B,C;
		cin>>A>>B>>C;
		int X, Y;
		C = pow10[C-1];
		for(int i = 1; i<50; i++)
		{
			if(num_digits(C*pow2[i]) == A)
			{
				X = C*pow2[i];
				break;
			}
		}
		for(int i = 1; i<50; i++)
		{
			if(num_digits(C*pow3[i]) == B)
			{
				Y = C*pow3[i];
				break;
			}
		}
		cout<<X<<" "<<Y<<endl;
	}
	return 0;
}
