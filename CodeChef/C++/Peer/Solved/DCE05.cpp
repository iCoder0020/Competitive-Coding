/*
ID: ishan_sang
PROG: DCE05
LANG: C++                  
*/
 
#include <iostream>
 
using namespace std;
 
int main()
{
    int T;
    cin>>T;
    int N;
    int ans;
    for(int t = 0; t<T; t++)
    {
        cin>>N;
        ans = 1;
        while(ans <= N)
        {
            ans *= 2;
        }
        ans /= 2;
        cout<<ans<<"\n";
    }
    return 0;
} 