/*
ID: ishan_sang
PROG: GMEDIAN
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N_MAX 1005
typedef long long int li;

li fact[N_MAX];
li C[N_MAX][N_MAX];
li C_sum[N_MAX][N_MAX];

li modular_exponentiation(li a, li b, li c)
{
	li result = 1;
	a = a%c;
	while(b>0)
	{
		if(b&1)
		{
			result = (result * a)%c;
		}
		b = b>>1;
		a = (a*a)%c;
	}
	return result;
}

li inversemod(li a, li p)
{
	return modular_exponentiation(a, p-2, p);
}

li calculate_nCr_mod_p(li n, li r, li p)
{
	if(r == 0)
	{
		return 1;
	}
	else if(n<=0 || n<r)
	{
		return 0;
	}
	else
	{
		return((((fact[n]%p * inversemod(fact[r], p)%p)%p) * inversemod(fact[n-r], p)%p)%p);
	}
}

int main()
{
	int T;
	fact[0] = 1;
	li sum;
	for(int n = 1; n<N_MAX; n++)
	{
		fact[n] = ((fact[n-1]%MOD)*n)%MOD;
	}
	for(int n = 0; n<N_MAX; n++)
	{
		for(int m = 0; m<N_MAX; m++)
		{
			C[n][m] = calculate_nCr_mod_p(n,m,MOD);
		
		}
	}
	for(int n = 0; n<N_MAX; n++)
	{
		C_sum[n][0] = C[0][n];
		for(int m = 1; m<N_MAX; m++)
		{
			C_sum[n][m] = (C_sum[n][m-1] + C[m][n])%MOD;		
		}
	}
	
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N;
		cin>>N;
		int A[N];
		int A_count[2*N+1] = {0};
		bool find_even = false;

		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			A_count[A[n]]++;
			if(A_count[A[n]] >= 2)
			{
				find_even = true;
			}
		}

		li odd_count = modular_exponentiation(2,N-1,MOD);
		li even_count = 0;
		li total_count;

		if(find_even == true)
		{
			sort(A,A+N);
			for(int i = 0; i<N; i++)
			{
				if(A_count[A[i]] >= 2)
				{
					int j = i+A_count[A[i]]-1;
					for(i; i<j; i++)
					{
						for(int k = 0; k<=i; k++)
						{
							if(N-2-j < 0)
							{
								even_count = (even_count + ((C[i][k])*( (C_sum[k][N-2-i]) ) )%MOD)%MOD;	
							}
							else
							{
								even_count = (even_count + ((C[i][k])*( (C_sum[k][N-2-i]) - (C_sum[k][N-2-j]) + MOD ) )%MOD)%MOD;
							}
						}
					}
				}
			}
		}
		total_count = (odd_count + even_count)%MOD;

		cout<<total_count<<endl;
	}
	return 0;
}