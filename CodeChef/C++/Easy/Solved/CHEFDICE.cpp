/*
ID: ishan_sang
PROG: CHEFDICE
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
        int possibilities[15][6]={{1,2,3,4,5,6},{1,2,3,5,4,6},{1,2,3,6,4,5},
                                  {1,3,2,4,5,6},{1,3,2,5,4,6},{1,3,2,6,4,5},
                                  {1,4,2,3,5,6},{1,4,2,5,3,6},{1,4,2,6,3,5},
                                  {1,5,2,3,4,6},{1,5,2,4,3,6},{1,5,2,6,3,4},
                                  {1,6,2,3,4,5},{1,6,2,4,3,5},{1,6,2,5,3,4}};
        int possibility_check[15];
        int o[6];
        int T,N;
        cin>>T;
        for(int i=0;i<T;i++)
        {
                for(int i=0;i<15;i++)
                {
                        possibility_check[i]=1;
                }
                cin>>N;
                int A[N];
                for(int j=0;j<N;j++)
                {
                        cin>>A[j];
                }
                for(int k=0;k<N-1;k++)
                {
                     for(int a=0;a<15;a++)
                        {
                                for(int b=0,c=1;b<6,c<6;b+=2,c+=2)
                                {
                                        if(A[k]==A[k+1])
                                        {
                                                for(int j=0;j<15;j++)
                                                        possibility_check[j]=0;
                                                break;
                                        }
                                        if((A[k]==possibilities[a][b]&&A[k+1]==possibilities[a][c])||(A[k+1]==possibilities[a][b]&&A[k]==possibilities[a][c]))
                                                possibility_check[a]=0;
                                }
                        }
                }
                for(int j=0;j<15;j++)
                {
                        if(possibility_check[j]==1)
                        {
                                for(int k=0;k<6;k+=2)
                                {
                                        o[possibilities[j][k]-1]=possibilities[j][k+1];
                                }
                                for(int k=1;k<6;k+=2)
                                {
                                        o[possibilities[j][k]-1]=possibilities[j][k-1];
                                }
                                for(int j=0;j<6;j++)
                                {
                                        cout<<o[j]<<" ";
                                }
                                break;
                        }
                        if(j==14)
                        {
                                cout<<"-1";
                        }
                }
                cout<<"\n";

        }
        return 0;
}
