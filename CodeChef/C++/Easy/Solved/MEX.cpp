/*
ID: ishan_sang
PROG: MEX
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N,K,S,k;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N>>K;
		int num[N+K];
		for(int j=0;j<N+K;j++)
		{
			num[j]=0;
		}
		for(int j=0;j<N;j++)
		{
			cin>>S;
			if(S<N+K)
				num[S]=1;
		}
		k=K;
		for(int j=0;j<N+K;j++)
		{
			if(num[j]==0 && k>0)
            {
                num[j]=1;
                k--;
            }
		}
		for(int j=0;j<N+K;j++)
        {
            if(num[j]==0)
            {
                cout<<j<<"\n";
                break;
            }
            if(j==N+K-1)
            {
                cout<<N+K<<"\n";
            }
        }
	}
	return 0;
}
