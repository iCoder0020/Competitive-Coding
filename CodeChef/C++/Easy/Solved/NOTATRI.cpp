/*
ID: ishan_sang
PROG: NOTATRI
LANG: C++                  
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
bool check(int x, int y, int z)
{
    if(x>y+z || y>x+z || z>x+y)
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
                int num = A[i]+A[j];
                int min = j+1;
                int max = N-1;
                int mid;
                while(min<=max)
                {
                    mid = (min+max)/2;
                    if(A[mid]>num)
                    {
                        if(A[mid-1]<=num)
                        {
                            count+=N-mid;
                            break;
                        }
                        else
                        {
                            max = mid - 1;
                        }
                    }
                    else
                    {
                        min = mid + 1;
                    }
                }
            }
        }
        cout<<count<<"\n";
    }
    return 0;
} 