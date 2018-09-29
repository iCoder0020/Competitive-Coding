/*
ID: iCoder0020
PROG: Gambling
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int B[N];
	long int scoreA = 0;
	long int scoreB = 0;
	long int player = 0;
	int lastA = N-1;
	int lastB = N-1;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	for(int n = 0; n<N; n++)
	{
		cin>>B[n];
	}
	sort(A,A+N);
	sort(B,B+N);
	while(lastA >= 0 || lastB >= 0)
	{
		if(player%2 == 0)
		{
			if(A[lastA] > B[lastB])
			{
				scoreA += A[lastA];
				lastA--;
			}
			else if(A[lastA] == B[lastB])
			{
				lastA--;
				lastB--;
			}
			else
			{
				lastB--;
			}
		}
		else
		{
			if(B[lastB] > A[lastA])
			{
				scoreB += B[lastB];
				lastB--;
			}
			else if(A[lastA] == B[lastB])
			{
				lastA--;
				lastB--;
			}
			else
			{
				lastA--;
			}
		}
		player++;
		if(lastA == -1)
		{
			while(lastB>=0)
			{
				if(player%2 == 0)
				{
					lastB--;
				}
				else
				{
					scoreB += B[lastB];
					lastB--;
				}
				player++;
			}
		}
		if(lastB == -1)
		{
			while(lastA>=0)
			{
				if(player%2 == 0)
				{
					scoreA += A[lastA];
					lastA--;
				}
				else
				{
					lastA--;
				}
				player++;
			}
		}
	}
	cout<<scoreA-scoreB<<"\n";
	return 0;
}