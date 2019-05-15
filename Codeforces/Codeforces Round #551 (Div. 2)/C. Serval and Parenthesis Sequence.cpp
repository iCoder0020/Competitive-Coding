/*
ID: iCoder0020
PROG: Serval and Parenthesis Sequence
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	if(N&1 || S[0] == ')' || S[N-1] == '(' || (N>2 && S[1] == ')'))
		cout<<":(";
	else
	{
		S[0] = '(';
		S[N-1] = ')';
		int l = 0;
		int r = 0;
		for(int n = 0; n<N; n++)
		{
			if(S[n] == '(')
				l++;
			else if(S[n] == ')')
				r++;
		}
		bool possible = true;
		int temp = 0;
		for(int n = 0; n<N; n++)
		{
			if(S[n] == '(')
				temp++;
			else if(S[n] == ')')
				temp--;
			else
			{
				if(l < N/2)
				{
					S[n] = '(';
					l++;
					temp++;
				}
				else
				{
					S[n] = ')';
					r++;
					temp--;
				}
			}
			if(temp < 0 || (temp == 0 && n<N-1))
				possible = false;
		}
		if(possible && temp == 0 && l == N/2 && r == N/2)
			cout<<S;
		else
			cout<<":(";
	}
	cout<<endl;
	return 0;
}