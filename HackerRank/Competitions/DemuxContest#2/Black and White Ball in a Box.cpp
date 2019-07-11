/*
ID: iCoder0020
PROG: Black and White Ball in a Box
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int N,M;
    cin>>N>>M;
    
    vector<int> boxes(N+1,1);
   
    set<int>S;
    S.insert(1);
    
    int x,y;
    
    while(M--)
    {
        cin>>x>>y;
        boxes[x]--;
        boxes[y]++;
       
       if(S.find(x) != S.end())
       {
           if(boxes[x] == 0)
           {
               S.erase(x);
           }
           S.insert(y);
       } 
    }

    cout<<S.size()<<endl;
    return 0;
}
