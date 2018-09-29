/*
ID: ishan_sang
PROG: KCON
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    long long int N, K;
    bool is_neg;
    long long int raw_sum;
    for(int t = 0; t<T; t++)
    {
        is_neg = false;
        raw_sum = 0; 
        cin>>N>>K;
        long long int A[N];
        for(int n = 0; n<N; n++)
        {
            cin>>A[n];
            raw_sum += A[n];
            if(A[n] < 0)
            {
                is_neg = true;
            }
        }
        if(!is_neg)
        {
            cout<<K*raw_sum<<"\n";
        }
        else
        {
            long long int max_sum, curr_sum;
            max_sum = A[0];
            curr_sum = A[0];
            if(K == 1)
            {
                for(int i = 1; i<N; i++)
                {
                    curr_sum = max(A[i], curr_sum + A[i]);
                    max_sum = max(max_sum, curr_sum);
                }
                cout<<max_sum<<"\n";
            }
            else
            {
                long long int B[2*N];
                int start = 0, end = 2*N-1;
                long long int ex_sum = 0;
                for(int i = 0; i<2*N; i++)
                {
                    B[i] = A[i%N];
                }
                for(int i = 1; i<2*N; i++)
                {
                    if(B[i] > curr_sum + B[i])
                    {
                        curr_sum = B[i];
                        start = i;
                    }
                    else
                    {
                        curr_sum += B[i];
                    }
                    if(max_sum < curr_sum)
                    {
                        max_sum = curr_sum;
                        end = i;
                    }
                }
                for(int i = start; i<=end; i++)
                {
                    ex_sum += B[i];
                }
                cout<<max(max_sum, ((K-2)*raw_sum + ex_sum))<<"\n";
            }
        }
    }
    return 0;
}