/*
ID: ishan-sang
PROG: Implement StrStr
LANG: C++                  
*/

int Solution::strStr(const string A, const string B) 
{
    if(A.size() == 0 || B.size() == 0 || A.size()<B.size())
        return -1;
    if(A == B)
        return 0;
    for(int i = 0; i<A.size()-B.size(); i++)
    {
        for(int j = 0; j<B.size();j++)
        {
            if(A[i+j] != B[j])
                break;
            if(j == B.size()-1)
                return i;
        }
    }
    return -1;
}