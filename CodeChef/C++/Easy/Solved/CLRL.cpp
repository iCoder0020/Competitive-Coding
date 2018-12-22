/*
ID: ishan_sang
PROG: CLRL
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    int N,R;
    for(int t = 0; t<T; t++)
    {
        cin>>N>>R;
        int A[N];
        int closest_left = -INT_MAX;
        int closest_right = INT_MAX;
        for(int n = 0; n<N; n++)
        {
            cin>>A[n];
        }
        for(int n = 0; n<N; n++)
        {
            if((A[n] >= closest_right && A[n] > R) || (A[n] <= closest_left && A[n] < R))
            {
                cout<<"NO\n";
                break;
            } 
            if(A[n] > R)
            {
                if(A[n] < closest_right)
                {
                    closest_right = A[n];
                }
            }
            if(A[n] < R)
            {
                if(A[n] > closest_left)
                {
                    closest_left = A[n];
                }
            }
            if(n == N-1)
            {
                if(A[N-1] != R)
                {
                    cout<<"NO\n";
                }
                else
                {
                    cout<<"YES\n";
                }
            }
        }
    }
    return 0;
}