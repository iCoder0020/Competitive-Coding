/*
ID: iCoder0020
PROG: Power digit sum
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define N_MAX 10000

string reverse(string S)
{
	string T = "";
	for(int i = S.length()-1; i>=0; i--)
	{
		T += S[i];
	}
	return T;
}

string twice(string S)
{
	string T = "";
	int carry = 0;
	int rem;
	int i;
	int small_sum;
	for(i = 0; i<S.length(); i++)
	{
		small_sum = carry + 2*((int)(S[i])-48);
		carry = small_sum/10;
		rem = small_sum%10;
		T += " ";
		T[i] = (char)(rem+48);
	}
	while(carry!=0)
	{
		T += " ";
		T[i] = (char)((carry%10)+48);
		carry /= 10;
		i++;
	}
	return T;
}

int main()
{
	int T, N;
	int sum;
	cin>>T;
	string powers[N_MAX];
	powers[0] = "2";
	for(int n = 1; n<N_MAX; n++)
	{
		powers[n] = reverse(twice(reverse(powers[n-1])));
	}
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		sum = 0;
		for(int i = 0; i<powers[N-1].length(); i++)
		{
			sum += int(powers[N-1][i]) - 48;
		}
		cout<<sum<<"\n";
	}
	return 0;
}