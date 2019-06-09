/*
ID: iCoder0020
PROG: Sort Array By Parity
LANG: C++                  
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) 
    {
        deque<int>B;
        for(auto it: A)
        {
            if(it&1)
                B.push_back(it);
            else
                B.push_front(it);
        }
        vector<int>C;
        for(auto it: B)
            C.push_back(it);
        return C;
    }
};