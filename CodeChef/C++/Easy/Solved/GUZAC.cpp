/*
ID: ishan_sang
PROG: GUZAC
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

li sum_up(li a, li b)
{
	li sum = 0;
	sum = (b*(b+1) - a*(a-1))/2;
	return sum;
}

using namespace std;

int main()
{
	int T;
	int N,K,X;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>K>>X;
		li A[K];
		li answer = 0;
		for(int k = 0; k<K; k++)
		{
			cin>>A[k];
			answer += A[k];
		}
		sort(A, A+K);

		int students_left = N-K;
		li max_limit = A[0] + X;
		int j = K-1;

		while(students_left != 0)
		{
			if(j == -1)
			{
				answer+=sum_up(A[0]-students_left, A[0]-1);
				students_left = 0;
			}
			if(max_limit > A[j])
			{
				int diff = max_limit - A[j];
				if(students_left >= diff)
				{
					answer = answer + sum_up(A[j]+1, max_limit);
					students_left-=diff;
					max_limit = A[j]-1;
				}
				else
				{
					answer+=sum_up(max_limit-students_left+1, max_limit);
					students_left = 0;
				}
			}
			else
			{	
				max_limit = A[j]-1;
				j--;
			}
		}
		cout<<answer<<endl;
	}
	return 0;
}