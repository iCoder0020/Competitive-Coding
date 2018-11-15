/*
ID: ishan_sang
PROG: STDDEV
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int t = 0; t<T; t++)
    {
        long double sigma;
        long long int N;
        cin>>N>>sigma;
        if(N ==1)
        {
            if(sigma == 0)
            {
                cout<<"1\n";
            }
            else
            {
                cout<<"-1\n";
            }
        }
        else
        {
            if(N%2 == 0)
            {
                for(long long int i = 0; i<N/2; i++)
                {
                    cout<<sigma<<" ";
                }
                for(long long int i = N/2; i<N; i++)
                {
                    cout<<-1*sigma;
                    if(i!=N-1)
                    {
                        cout<<" ";
                    }
                }
                cout<<"\n";
            }
            else
            {
                long double temp = sqrtf((float)(N)/((float)(N-1)));
                sigma = sigma*temp;
                cout<<"0 ";
                for(long long int i = 0; i<N/2; i++)
                {
                    cout<<sigma<<" ";
                }
                for(long long int i = N/2+1; i<N; i++)
                {
                    cout<<-1*sigma;
                    if(i!=N-1)
                    {
                        cout<<" ";
                    }
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}