/*
ID: iCoder0020
PROG: Extra Long Factorials
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

string stringit(int num)
{
	string n;
	while(num)
	{
		n += (char)(num%10+48);
		num /= 10;
	}
	reverse(n.begin(), n.end());
	return n;
}

string multiply(string str1, string str2)
{
	string partial_product[str2.length()], fact;

	int n, carry;

	for(int j = str2.length()-1; j>=0; j--)
	{
		carry = 0;	
		for(int i = str1.length()-1; i>=0; i--)
		{
			n = ((int)(str2[j])-48)*((int)(str1[i])-48)+carry;
			partial_product[str2.length()-j-1] += (char)(n%10+48);
			carry = n/10;
		}
		if(carry != 0)
		{
			partial_product[str2.length()-j-1] += (char)(carry+48);
			carry = 0;
		}
	}
	
	for(int i = 0; i<str2.length(); i++)
	{
		reverse(partial_product[i].begin(), partial_product[i].end());
		for(int j = 0; j<i; j++)
		{
			partial_product[i] += "0";
		}
		reverse(partial_product[i].begin(), partial_product[i].end());
	}

	fact = partial_product[str2.length()-1];
	for(int i = 0; i<str2.length()-1; i++)
	{
		carry = 0;
		for(int j = 0; j<partial_product[i].length(); j++)
		{
			n = (int)(fact[j]-48)+(int)(partial_product[i][j]-48)+carry;
			fact[j] = (char)(n%10+48);
			carry = n/10;
			if(j == partial_product[i].length()-1)
			{
				while(carry != 0)
				{
					if(j < fact.length()-1)
					{
						n = (int)(fact[j+1]-48)+carry;
						fact[j+1] = (char)(n%10+48);
						carry = n/10;
					}
					else
					{
						n = carry;
						fact += (char)(n%10+48);
						carry = n/10;
					}
					j++;
				}
			}
		}
	}
	reverse(fact.begin(), fact.end());
	return fact;
}

int main()
{
	int T,N;
    string factorial;
    cin>>N;
    if(N <= 0)
    {
        cout<<"1\n";
    }
    else
    {
        factorial = stringit(N);
        for(int i = 1; i<N ;i++)
        {
            factorial = multiply(factorial, stringit(N-i));
        }
    }
    cout<<factorial<<"\n";
	return 0;
}
