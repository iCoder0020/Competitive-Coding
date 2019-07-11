/*
ID: ishan-sang
PROG: Single Number
LANG: C++                  
*/

int Solution::singleNumber(const vector<int> &A) 
{
    int x = 0;
    for(auto it: A)
        x = x^it;
    return x;
}
