/*
ID: ishan_sang
PROG: DESORT
LANG: C++
*/
 
#include <bits/stdc++.h>

using namespace std;
 
bool mysort(string A, string B)
{
	if(A.length() > B.length())
	{
		return true;
	}
	else if(A.length() < B.length())
	{
		return false;
	}
	else
	{
		int len = A.length();
		int i = 0;
		while(i!=len)
		{
			if(A[i] > B[i])
			{
				return true;
			}
			else if(A[i] < B[i])
			{
				return false;
			}
			i++;
		}
	}
	return false;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		string S[N];
		for(int n = 0; n<N; n++)
		{
			cin>>S[n];
		}
		sort(S, S+N, mysort);
		for(int n = 0; n<N; n++)
		{
			cout<<S[n]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
 