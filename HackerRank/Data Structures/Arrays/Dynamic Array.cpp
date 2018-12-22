/*
ID: iCoder0020
PROG: Dynamic Array
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,Q;
    cin>>N>>Q;
    vector<int> seqList[N];
    int choice,X,Y;
    int lastAnswer = 0;
    for(int q = 0; q<Q; q++)
    {
        cin>>choice>>X>>Y;
        int temp = (X^lastAnswer)%N;
        switch(choice)
        {
            case 1:
                seqList[temp].push_back(Y);
                break;
            case 2:
                lastAnswer = seqList[temp][Y%seqList[temp].size()];
                cout<<lastAnswer<<endl;
                break;
        }
    }
    return 0;
}