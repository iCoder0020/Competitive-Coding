/*
ID: ishan_sang
PROG: MINEAT
LANG: C++                  
*/
 
#include <bits/stdc++.h>
 
using namespace std;

bool f(int A[], int N, int H, int rate)
{
    int time = 0;
    for(int n = 0; n<N; n++)
    {
        time += A[n]/rate;
        if(A[n]%rate)
        {
            time++;
        }
    }
    //cout<<rate<<" "<<time<<endl;
    if(time <= H)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,H;
        cin>>N>>H;
        int A[N];
        for(int n = 0; n<N; n++)
        {
            cin>>A[n];
        }
        int min = 1;
        int max = 1000000000;
        int mid;
        while(1)
        {
            mid = (min+max)/2;
            if(min == max)
            {
                cout<<mid<<endl;
                break;
            }
            else if(f(A, N, H, mid))
            {
                max = mid;
            }
            else
            {
                min = mid+1;
            }
        }
    }
    return 0;
} 