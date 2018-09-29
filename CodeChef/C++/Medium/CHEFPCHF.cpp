/*
ID: ishan_sang
PROG: CHEFPCHF
LANG: C++
*/
 
#include <string.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
 
int main()
{
        int T;
        int N,K;
        int l=0;
        int index,num;
        int ans=0;
        int c;
        cin>>T;
        for(int i=0;i<T;i++)
        {
                cin>>N;
                ans=0;
                int A[N];
                for(int j=0;j<N;j++)
                {
                        A[j]=0;
                }
                cin>>K;
                for(int j=0;j<K;j++)
                {
                       cin>>index>>num;
                       A[index-1]=num;
                }
                for(int a=0;a<(N/2+N%2);a++)
                {
                        for(int j=0,k=2*a;j<N,k<N;j++,k++)
                        {
                                int c=0;
                                int r=0;
                                for(int b=j;b<=k;b++)
                                {
                                       r++;
                                       if(A[b]==A[k+j-b])
                                       {
                                                c++;
                                       }
                                }
                                if(c==r)
                                {
                                        ans++;
                                }
                        }
 
 
                }
                cout<<ans<<"\n";
        }
        return 0;
}
 