/*
ID: ishan_sang
PROG: MAXEP
LANG: C++
*/

#include <iostream>
 
using namespace std;
 
int main()
{
    int N,c;
    cin>>N>>c;
    int guess = 1;
    int broken;
    bool got_answer = false;
    int inc = max(N/250, 1);
    while(1)
    {
        cout<<1<<" "<<guess<<endl;
        cin>>broken;
        if(broken == 1)
        {
            cout<<2<<endl;
            if(guess == 1)
            {
                cout<<3<<" "<<guess<<endl;
                got_answer = true;
            }
            else
            {
                if(inc != 1)
                {
                    for(int i = guess-(inc-1); i<=guess; i++)
                    {
                        cout<<1<<" "<<i<<endl;
                        cin>>broken;
                        if(broken == 1)
                        {
                            cout<<2<<endl;
                            got_answer = true;
                            cout<<3<<" "<<i<<endl;
                            break;
                        }
                    }
                }
                else
                {
                    got_answer = true;
                    cout<<3<<" "<<guess<<endl;
                    break;
                }
            }
        }
        if(got_answer)
        {
            break;
        }
        else
        {
            guess += inc;
        }
    }
    return 0;
} 