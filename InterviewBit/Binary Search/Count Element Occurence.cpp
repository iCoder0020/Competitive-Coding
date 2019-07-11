/*
ID: ishan-sang
PROG: Count Element Occurence
LANG: C++                  
*/

int Solution::findCount(const vector<int> &A, int B) 
{
    int i = lower_bound(A.begin(), A.end(), B) - A.begin();
    int j = upper_bound(A.begin(), A.end(), B) - A.begin();
    return j-i;
}
