/*
ID: iCoder0020
PROG: Palindromic Matrix
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int temp;
	if(N == 1)
	{
		cin>>temp;
		cout<<"YES"<<endl;
		cout<<temp<<endl;
	}
	else
	{
		int freq[1001] = {0};
		bool found;
		int A[N][N];
		multiset<int>square;
		multiset<int>rect;
		int c;
		for(int n = 0; n<N*N; n++)
		{
			cin>>temp;
			freq[temp]++;
		}
		if(N%2 == 0)
		{
			for(int n = 1; n<1001; n++)
			{
				if(freq[n] >= 4)
				{
					for(int i = 0;i <freq[n]/4; i++)
					{
						square.insert(n);
					}
				}
				freq[n] -= (freq[n]/4)*4;
			}
			if(square.size()<(N/2)*(N/2))
			{
				cout<<"NO"<<endl;
			}
			else
			{
				cout<<"YES"<<endl;
				int B[N/2][N/2];
				for(int i = 0; i<N/2; i++)
				{
					for(int j = 0; j<N/2; j++)
					{
						auto it = square.begin();
						B[i][j] = *(it);
						square.erase(it);
					}
				}
				for(int i = 0; i<N/2; i++)
				{
					for(int j = 0; j<N/2; j++)
					{
						A[i][j] = B[i][j];
					}
				}
				for(int i = 0; i<N/2; i++)
				{
					for(int j = N/2; j<N; j++)
					{
						A[i][j] = B[i][N-j-1];
					}
				}
				for(int i = N/2; i<N; i++)
				{
					for(int j = 0; j<N/2; j++)
					{
						A[i][j] = B[N-i-1][j];
					}
				}
				for(int i = N/2; i<N; i++)
				{
					for(int j = N/2; j<N; j++)
					{
						A[i][j] = B[N-i-1][N-j-1];
					}
				}

				for(int i = 0; i<N; i++)
				{
					for(int j = 0; j<N; j++)
					{
						cout<<A[i][j]<<" ";
					}
					cout<<endl;
				}
			}
		}
		else
		{
			int req = (N/2)*(N/2);
			int i;
			for(int n = 1; n<1001; n++)
			{
				if(freq[n] >= 4 && square.size() != req)
				{
					for(i = 0; i<freq[n]/4; i++)
					{
						square.insert(n);
						if(square.size() == req)
						{
							i++;
							break;
						}
					}
					freq[n] -= i*4;
				}
				if(square.size() == req)
				{
					break;
				}
			}
			req = N-1;
			for(int n = 1; n<1001; n++)
			{
				if(freq[n] >= 2 && rect.size() != req)
				{
					for(i = 0; i<freq[n]/2; i++)
					{
						rect.insert(n);
						if(rect.size() == req)
						{
							i++;
							break;
						}
					}
					freq[n] -= i*2;
				}
				if(rect.size() == req)
				{
					break;
				}
			}
			c = -1;
			for(int n = 1; n<1001; n++)
			{
				if(freq[n] > 0)
				{
					c = n;
					break;
				}
			}
			if(c == -1 || rect.size() < N-1 || square.size() < (N/2)*(N/2))
			{
				cout<<"NO"<<endl;
			}
			else
			{
				cout<<"YES"<<endl;
				int B[N/2][N/2];
				for(int i = 0; i<N/2; i++)
				{
					for(int j = 0; j<N/2; j++)
					{
						auto it = square.begin();
						B[i][j] = *(it);
						square.erase(it);
					}
				}
				for(int i = 0; i<N/2; i++)
				{
					for(int j = 0; j<N/2; j++)
					{
						A[i][j] = B[i][j];
					}
				}
				for(int i = 0; i<N/2; i++)
				{
					for(int j = N/2; j<N; j++)
					{
						A[i][j] = B[i][N-j-1];
					}
				}
				for(int i = N/2; i<N; i++)
				{
					for(int j = 0; j<N/2; j++)
					{
						A[i][j] = B[N-i-1][j];
					}
				}
				for(int i = N/2; i<N; i++)
				{
					for(int j = N/2; j<N; j++)
					{
						A[i][j] = B[N-i-1][N-j-1];
					}
				}

				int mid = N/2;

				for(int i = 0; i<N/2; i++)
				{
					auto it = rect.begin();
					A[i][mid] = *(it);
					A[N-i-1][mid] = *(it);
					rect.erase(it);
				}

				A[mid][mid] = c;

				for(int i = 0; i<N/2; i++)
				{
					auto it = rect.begin();
					A[mid][i] = *(it);
					A[mid][N-i-1] = *(it);
					rect.erase(it);
				}

				for(int i = 0; i<N; i++)
				{
					for(int j = 0; j<N; j++)
					{
						cout<<A[i][j]<<" ";
					}
					cout<<endl;
				}
			}
		}
	}
	return 0;
}