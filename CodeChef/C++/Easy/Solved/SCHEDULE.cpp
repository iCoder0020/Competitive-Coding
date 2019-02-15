/*
ID: ishan_sang
PROG: SCHEDULE
LANG: C++                  
*/
 
#include <bits/stdc++.h>
 
using namespace std;

bool check(int A[], int N, int K, int cons)
{
    int count = 0;
    int prev;
    if(cons == 1)
    {
        int ans1 = 0;
        int ans2 = 0;
        for(int n = 0; n<N; n++)
        {
            if(A[n] != n%2)
            {
                ans1++;
            }
            else
            {
                ans2++;
            }
        }
        if(min(ans1, ans2) > K)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        for(int n = 0; n<N; n++)       
        {
            if(n == 0)
            {
                prev = A[n];
                count++;
            }
            else
            {
                while(n<N && A[n] == prev)
                {
                    n++;
                    count++;
                }        
                if(count > cons)
                {
                    K -= count/(cons+1);
                    if(K < 0)
                    {
                        return false;
                    }
                }
                count = 1;
                prev = A[n];
            }
        }
    }
    return true;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N, K;
        cin>>N>>K;
        int A[N];
        string s;
        cin>>s;
        for(int n = 0; n<N; n++)
        {
            A[n] = s[n] - 48;
        }
        int min = 1;
        int max = N;
        int mid;
        while(1)
        {
            mid = (min + max)/2;
            // cout<<min<<" "<<max<<" "<<mid<<endl;
            if(max - min <= 1)
            {
                if(check(A, N, K, min))
                {
                    mid = min;
                }
                else
                {
                    mid = max;
                }
                break;
            }
            else if(check(A, N, K, mid))
            {
                max = mid;
            }
            else
            {
                min = mid + 1;
            }
        }
        cout<<mid<<endl;
    }
    return 0;
} 