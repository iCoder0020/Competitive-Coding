/*
ID: ishan-sang
PROG: Power Of Two Integers
LANG: C++                  
*/

int Solution::isPower(int A) 
{
    if(A == 1)
        return 1;
    for(int i = 2; i<=sqrt(INT_MAX); i++)
    {
        long long int x = i;
        while(x>0 && x<=INT_MAX)
        {
            //cout<<x<<endl;
            x*=i;
            if(A == x)
                return 1;
        }
    }
    return 0;
}


