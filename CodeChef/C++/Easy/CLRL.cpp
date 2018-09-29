/*
ID: ishan_sang
PROG: CLRL
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    int N,R;
    int t;
    int closest_max,closest_min;
    for(int i=0;i<T;i++)
    {
        t=1;
        cin>>N>>R;
        int A[N];
        closest_max=0;
        closest_min=0;
        if(N<=2)
        {
            cout<<"YES\n";
        }
        else
        {
            for(int j=0;j<N;j++)
            {
                cin>>A[j];
                if(t!=0)
                {
                    if(A[j]<R)
                    {
                        if(closest_min==0)
                        {
                            closest_min=R-A[j];
                        }
                        else
                        {
                            closest_min=((R-A[j])<closest_min)?(R-A[j]):closest_min;
                            if((R-A[j])>closest_min)
                            {
                                cout<<"NO\n";
                                t=0;
                            }
                        }
                    }
                    if(A[j]>R)
                    {
                        if(closest_max==0)
                        {
                            closest_max=A[j]-R;
                        }
                        else
                        {
                            closest_max=((A[j]-R)<closest_max)?(A[j]-R):closest_max;
                            if((A[j]-R)>closest_max)
                            {
                                cout<<"NO\n";
                                t=0;
                            }
                        }
                    }
                    if(j==N-1)
                    {
                        cout<<"YES\n";
                    }
                }
            }
        }
    }
    return 0;
}