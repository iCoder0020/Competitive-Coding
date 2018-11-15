/*
ID: ishan_sang
PROG: ICPC16F
LANG: C++                  
*/
 
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
    int n,m,d,D;
    cin>>T;
    for(int t = 0; t<T; t++)
    {
        cin>>n>>m>>d>>D;
        bool flag = false;
        if(n*d <= m && m <= n*D)
        {
            for(int k = 0; k<=n; k++)
            {
                for(int i = 1; i<=n; i++)
                {
                    if(m == 0)
                    {
                        flag = true;
                        break;
                    }
                    cout<<i<<" "<<((i-1+k)%n)+1<<"\n";
                    m--;
                }
                if(flag)
                {
                    break;
                }
            }
        }
        else
        {
            cout<<"-1\n";
        }
    }
} 