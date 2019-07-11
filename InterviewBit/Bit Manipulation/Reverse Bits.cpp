/*
ID: ishan-sang
PROG: Reverse Bits
LANG: C++                  
*/

unsigned int Solution::reverse(unsigned int A) 
{
    long long int ans = 0;
    string s = "00000000000000000000000000000000";
    int n = 31;
    while(A)
    {
        if(A&1)
            s[n]='1';
        n--;
        A/=2;
    }
    std::reverse(s.begin(), s.end());
    long long int pow2[40] = {0};
    pow2[0] = 1;
    for(int n = 1; n<40; n++)
        pow2[n] = 2*pow2[n-1];
    for(int n = 0; n<32; n++)
    {
        if(s[n] == '1')
            ans += pow2[31-n];
    }
    return ans;
}
