/*
ID: ishan-sang
PROG: Grid Unique Paths
LANG: C++                  
*/

int Solution::uniquePaths(int A, int B) 
{
    long long int ans = 1;
    for(int i = A; i<= A+B-2; i++)
    {
        ans *= i;
        ans /= (i-A+1);
    }
    return ans;
}
