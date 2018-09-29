/*
ID: ishan_sang
PROG: PERPALIN
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    int N,P;
    cin>>T;
    int c;
    for(int i=0;i<T;i++)
    {
        c=1;
        cin>>N>>P;
        if(P<3)
        {
            cout<<"impossible";
            c=0;
        }
        if(c)
        {
            string A="";
            string B="";
            string C="";
            if(P%2==0)
            {
                for(int j=0;j<P/2;j++)
                {
                    A+=(j%2==0)?'a':'b';
                }
            }
            else
            {
                for(int j=0;j<P/2+1;j++)
                {
                    A+=(j%2==0)?'a':'b';
                }
            }

            if(P%2==0)
            {
                    for(int j=0;j<P/2;j++)
                    {
                        B+=(j%2==0)?'b':'a';
                    }
            }
            else
            {
                for(int j=0;j<P/2;j++)
                    {
                        B+=(j%2==0)?'a':'b';
                    }
            }
            C=A+B;
            for(int k=0;k<N/P;k++)
                cout<<C;
        }
        cout<<"\n";
    }
    return 0;
}
