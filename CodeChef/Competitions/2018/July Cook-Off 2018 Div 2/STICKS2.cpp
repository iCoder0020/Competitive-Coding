/*
ID: ishan_sang
PROG: STICKS2
LANG: C++                  
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	int N,K;
	int num;
	int num_extras;
	bool we_can_leave_one;
	bool found_answer;
	long int edges[2];
	long int answer;
	int count;
	int pair_count;
	cin>>T;
	for(int t = 0; t<T; t++)
	{	
		count = 0;
		cin>>N>>K;
		int A[N];
		int copies[N]={0};
		num_extras = 0;
		we_can_leave_one = false;
		found_answer = false;
		pair_count = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		sort(A, A+N);
		for(int n = 0; n<N; n++)
		{
			if(A[n] != A[num] || n == 0)
			{
				num = n;
			}
			copies[num]++;
		}
		for(int n = 0; n<N; n++)
		{
			if(copies[n] > 1)
			{
				pair_count+=copies[n]/2;
				num_extras += copies[n] - 1;
				if(copies[n] < 4)
				{
					if(we_can_leave_one == false && K != N)
					{
						we_can_leave_one = true;
						num_extras -= copies[n] - 1;
					}
				}
			}
		}
		if(num_extras - (N-K) < 1 || pair_count<2)
		{
			cout<<"-1\n";
		}
		else
		{
			for(int n = N-1; n>=0; n--)
			{
				if(copies[n] >= 2)
				{
					if((N-K) - (copies[n]-1) >= 0)
					{
						K += copies[n]-1;
						if((N-K) == 0)
						{
							found_answer = true;
							for(int m = n-1; m>=0; m--)
							{
								if(copies[m]>=4 && count == 0)
								{	
									edges[0] = A[m];
									edges[1] = A[m];
									break;
								}
								if(copies[m]>=2)
								{
									edges[count] = A[m];
									count++;
								}
								if(count == 2)
								{
									break;
								}
							}
						}
					}
					else
					{
						found_answer = true;
						for(int m = n; m>=0; m--)
						{
							if(copies[m]>=4 && count == 0)
							{	
								edges[0] = A[m];
								edges[1] = A[m];
								break;
							}
							if(copies[m]>=2)
							{
								edges[count] = A[m];
								count++;
							}
							if(count == 2)
							{
								break;
							}
						}
					}
				}
				if(found_answer == true)
				{
					break;
				}
			}
			answer = edges[0]*edges[1];
			cout<<answer<<"\n";
		}
	}
	return 0;
}