/*
ID: ishan-sang
PROG: Sorted Insert Position
LANG: C++                  
*/

int Solution::searchInsert(vector<int> &A, int B) 
{
    int i = lower_bound(A.begin(), A.end(), B) - A.begin();
    return i;
}
