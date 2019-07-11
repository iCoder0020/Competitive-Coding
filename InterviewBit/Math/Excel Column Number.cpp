/*
ID: ishan-sang
PROG: Excel Column Number
LANG: C++                  
*/

int Solution::titleToNumber(string A) 
{
    long long int pow26[10];
    pow26[0] = 1;
    for(int n = 1; n<10; n++)
        pow26[n] = 26*pow26[n-1];
    int ans = 0;
    int N = A.length();
    int cnt = 0;
    for(auto it: A)
    {
        ans +=  (it-'A'+1)*pow26[N-cnt-1];
        cnt++;
    }
    return ans;
}
