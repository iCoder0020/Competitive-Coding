/*
ID: ishan-sang
PROG: Stairs
LANG: C++                  
*/

int Solution::climbStairs(int A) 
{
    if(A < 2)
        return 1;
    if(A == 2)
        return 2;
    return climbStairs(A-1) + climbStairs(A-2);
}
