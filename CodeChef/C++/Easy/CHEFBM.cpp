/*
ID: ishan_sang
PROG: CHEFBM
LANG: C++                  
*/
 
#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int N,M,P;
    int I,J;
    cin>>N>>M>>P;
    vector< vector<int> >ARR(N, vector<int>(M, 1));
    vector<int>ROW(N, M-1);
    vector<bool>FLAG(N);
    for(int p = 0; p<P; p++)
    {
        cin>>I>>J;
        if(J == M)
        {
            ARR[I-1][J-2]++;
            ROW[I-1]++;
        }
        else
        {
            ARR[I-1][J-1]--;
            if(J >= 2)
            {
                ARR[I-1][J-2]++;    
            }
            if(J == 1)
            {
                ROW[I-1]--;
            }
        }
        if(ARR[I-1][J-1] < 0)
        {
            FLAG[I-1] = true;
        }
        else
        {
            FLAG[I-1] = false;
        }
    }
    for(int i = 0; i<N; i++)
    {
        if(FLAG[i])
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<ROW[i]<<"\n";
        }
    }
    return 0;
} 