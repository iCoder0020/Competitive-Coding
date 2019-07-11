/*
ID: ishan-sang
PROG: Prime Sum
LANG: C++                  
*/

vector<int> Solution::primesum(int A) {
    vector<int> ans;
    if(A == 4)
    {
        ans.push_back(2);
        ans.push_back(2);
    }
    else
    {
        vector<bool> sieve(A+1, true);
        for(int i = 2; i<=sqrt(A); i++)
        {
            for(int j = 2; i*j<=A; j++)
            {
                sieve[i*j] = false;
            }
        }
        for(int i = 3; i<A; i+=2)
        {
            if(sieve[i] && sieve[A-i])
            {
                ans.push_back(i);
                ans.push_back(A-i);
                break;
            }
        }
    }
    return ans;
}


