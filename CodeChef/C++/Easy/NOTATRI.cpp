/*
ID: ishan_sang
PROG: NOTATRI
LANG: C++                  
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int N;
    int count;
    while(1)
    {
        cin>>N;
        count = 0;
        if(N == 0)
        {
            break;
        }
        int A[N];
        for(int n = 0; n<N; n++)
        {
            cin>>A[n];
        }
        sort(A, A+N);
        for(int i = 0; i<N-2; i++)
        {
            for(int j = i+1; j<N-1; j++)
            {
                int low, mid, high;
                low = j+1;
                high = N-1;
                if(low == high)
                {
                    if(A[low] > A[i] + A[j])
                    {
                        count++;
                    }
                    continue;
                }
                while(low < high)
                {
                    mid = (low + high)/2;
                    if(A[mid] < A[i] + A[j])
                    {
                        low = mid+1;
                    }
                    if(A[mid] > A[i] + A[j])
                    {
                        high = mid-1;
                    }
                    if(A[mid] == A[i] + A[j])
                    {
                        count += N-mid-1;
                        break;
                    }
                }
                if(A[mid] != A[i] + A[j])
                {
                    if(A[mid-1] > A[i] + A[j])
                    {
                        count += N-mid+1;
                    }
                    else if(A[mid] > A[i] + A[j])
                    {
                        count += N-mid;
                    }
                    else if(mid+1 < N)
                    {
                        if(A[mid+1] > A[i] + A[j])
                        {
                            count += N-mid-1;
                        }
                    }
                    else
                    {
 
                    }
                }
            }
        }
        cout<<count<<"\n";
    }
    return 0;
} 