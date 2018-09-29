/*
ID: iCoder0020
PROG: Large sum
LANG: C++                  
*/

#include <bits/stdc++.h>

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

int main()
{
	int N;
	int index;
	cin>>N;
	string numbers[N];
	string sum = "";
	for(int i = 0; i<N; i++)
	{
		cin>>numbers[i];
		numbers[i] = reverse(numbers[i]);
	}	
	int small_sum;
	int rem;
	int carry = 0;
	for(index = 0; index<50; index++)
	{
		small_sum = carry;
		for(int j = 0; j<N; j++)
		{
			small_sum += (int)(numbers[j][index])-48;
		}
		carry = small_sum/10;
		rem = small_sum%10;
		sum += " ";
		sum[index] = (char)(rem+48);
	}
	while(carry!=0)
	{
		sum += " ";
		sum[index] = (char)((carry%10)+48);
		carry /= 10;
		index++;
	}
	sum = reverse(sum);
	for(int i = 0; i<10; i++)
	{
		cout<<sum[i];
	}
	cout<<"\n";
	return 0;
}