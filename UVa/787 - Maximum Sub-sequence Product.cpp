/*
ID: iCoder0020
PROG: 787 - Maximum Sub-sequence Product
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

string maxm(string A, string B)
{
	int lenA = A.length();
	int lenB = B.length();
	if(A[0] != '-' && B[0] == '-')
	{
		return A;
	}
	else if(B[0] != '-' && A[0] == '-')
	{
		return B;
	}
	else if(lenA > lenB)
	{
		if(A[0] != '-')
		{
			return A;
		}
		else
		{
			return B;
		}
	}
	else if(lenB > lenA)
	{
		if(A[0] != '-')
		{
			return B;
		}
		else
		{
			return A;
		}
	}
	else
	{
		if(A[0] != '-' && B[0] != '-')
		{
			for(int n = 0; n<lenA; n++)
			{
				if(A[n] > B[n])
				{
					return A;
				}
				else if(A[n] < B[n])
				{
					return B;
				}
			}
		}
		else
		{
			for(int n = 0; n<lenA; n++)
			{
				if(A[n] > B[n])
				{
					return B;
				}
				else if(A[n] < B[n])
				{
					return A;
				}
			}
		}
		return A;
	}
}

string minm(string A, string B)
{
	int lenA = A.length();
	int lenB = B.length();
	if(A[0] != '-' && B[0] == '-')
	{
		return B;
	}
	else if(B[0] != '-' && A[0] == '-')
	{
		return A;
	}
	else if(lenA > lenB)
	{
		if(A[0] != '-')
		{
			return B;
		}
		else
		{
			return A;
		}
	}
	else if(lenB > lenA)
	{
		if(A[0] != '-')
		{
			return A;
		}
		else
		{
			return B;
		}
	}
	else
	{
		if(A[0] != '-' && B[0] != '-')
		{
			for(int n = 0; n<lenA; n++)
			{
				if(A[n] > B[n])
				{
					return B;
				}
				else if(A[n] < B[n])
				{
					return A;
				}
			}
		}
		else
		{
			for(int n = 0; n<lenA; n++)
			{
				if(A[n] > B[n])
				{
					return A;
				}
				else if(A[n] < B[n])
				{
					return B;
				}
			}
		}
		return A;
	}
}

string mul(string A, string B)
{
	bool neg = false;
	int lenA = A.length();
	int lenB = B.length();
	
	if((A[0] == '0' && lenA == 1) || (B[0] == 0 && lenB == 1))
	{
		return "0";
	}

	if(A[0] == '-' && B[0] != '-')
	{
		neg = true;
	}
	if(A[0] != '-' && B[0] == '-')
	{
		neg = true;
	}
	if(A[0] == '-')
	{
		A = A.substr(1, lenA-1);
	}
	if(B[0] == '-')
	{
		B = B.substr(1, lenB-1);
	}
	
	string C = max(A, B);
	B = min(A, B);
	A = C;

	lenA = A.length();
	lenB = B.length();

	string parts[lenB];
	string product;

	int max_len = 0;

	for(int n = 0; n<lenB; n++)
	{
		char carry = '0';
		int mini_prod;	
		char num = B[lenB-1-n];

		parts[n] = "";
		for(int i = lenA-1; i>=0; i--)
		{
			mini_prod = ( ((int)(num) - 48) * ((int)(A[i]) - 48) ) + ((int)(carry) - 48);
			parts[n] += (char)(mini_prod%10 + 48);
			carry = (char)(mini_prod/10 + 48);
		}
		if(carry != '0')
		{
			parts[n]+=carry;
		}
		reverse(parts[n].begin(), parts[n].end());
		for(int m = 0; m<n; m++)
		{
			parts[n]+='0';
		}
		
		max_len = max(max_len, (int)(parts[n].length()));
	}

	for(int n = 0; n<lenB; n++)
	{
		reverse(parts[n].begin(), parts[n].end());
		while(parts[n].length() != max_len)
		{
			parts[n] += '0';
		}
		reverse(parts[n].begin(), parts[n].end());
	}	

	int carry = 0;
	for(int n = 0; n<max_len; n++)
	{
		int mini_sum = 0;	

		for(int m = 0; m<lenB; m++)
		{
			mini_sum += ((int)(parts[m][max_len-n-1]) - 48);
		}

		mini_sum += carry;
		product += ((char)(mini_sum%10) + 48);
		carry = mini_sum/10;
	}
	while(carry != 0)
	{
		product += ((char)(carry%10) + 48);
		carry /= 10; 
	}

	reverse(product.begin(), product.end());

	if(neg)
	{
		product = "-" + product;
	}

	return product;
}

int main()
{
	string S;
	while(getline(cin, S))
	{	
		vector<string> A;
		int i = 0;
		int j = 0;
		for(int n = 0; n<S.length(); n++)
		{
			if(S[n] == ' ')
			{
				j = n-1;
				A.push_back(S.substr(i, j-i+1));
				i = j+2;
			}
		}
		int N = A.size();
		string dp[N][2];
		dp[N-1][0] = A[N-1];
		dp[N-1][1] = A[N-1];
		string max_product = A[N-1];
		for(int n = N-2; n>=0; n--)
		{
			if(A[n][0] != '-')
			{
				dp[n][0] = maxm(A[n], mul(A[n],dp[n+1][0]));
				dp[n][1] = minm(A[n], mul(A[n],dp[n+1][1]));
			}
			else
			{
				dp[n][0] = maxm(A[n], mul(A[n],dp[n+1][1]));
				dp[n][1] = minm(A[n], mul(A[n],dp[n+1][0]));
			}
			max_product = maxm(max_product, dp[n][0]);
		}
		cout<<max_product<<endl;
	}
	return 0;
}