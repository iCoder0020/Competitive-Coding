/*
ID: ishan_sang
PROG: SHKNUM
LANG: C++                  
*/

#include <iostream>

using namespace std;

string reverse(string S)
{
	string T = "";
	for(int i = S.length()-1; i>=0; i--)
	{
		T += S[i];
	}
	return T;
}

string to_binary(int N)
{
	string S = "";
	int rem;
	while(N)
	{
		rem = N%2;
		S += char(rem + 48);
		N/=2;
	}
	return reverse(S);
}

int to_decimal(string S)
{
	int N = 0;
	int multiplier = 1;
	S = reverse(S);
	for(int i = 0; i<S.length(); i++)
	{
		N += (int(S[i])-48)*multiplier;
		multiplier *= 2;
	}
	return N;
}

int main()
{
	int T,N;
	string S;
	int index1, index2;
	int min;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		if(N == 1)
		{
			cout<<"2\n";
			continue;
		}
		index1 = -1;
		index2 = -1;
		S = (to_binary(N));
		for(int i = 0; i<S.length(); i++)
		{
			if(S[i] == '1')
			{
				if(index1 == -1)
				{
					index1 = i;
					continue;
				}
				if(index1 != -1 && index2 == -1)
				{
					index2 = i;
					break;
				}
			}
		}
		if(index2 == -1)
		{
			cout<<"1\n";
		}
		else
		{
			for(int i = index2+1; i<S.length(); i++)
			{
				S[i] = '0';
			}
			min = N - to_decimal(S);
			S[index2] = '0';
			if(index2 == index1 + 1)
			{
				S += "1";
			}
			else
			{
				S[index2 - 1] = '1';
			}
			min = (min<(to_decimal(S)-N))?min:(to_decimal(S)-N);
			cout<<min<<"\n";
		}
	}
	return 0;
}