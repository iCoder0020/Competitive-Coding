/*
ID: ishan-sang
PROG: Implement Power Function
LANG: C++                  
*/

int Solution::pow(int y, int n, int d) 
{
    long long int x = y;
    long long int result = 1;
    while(x < 0)
        x += d;
    x = x%d;
    while(n > 0)
    {
        if(n&1)
            result = (result*x)%d;
        n/=2;
        x = (x*x)%d;
    }
    return result%d;
}
