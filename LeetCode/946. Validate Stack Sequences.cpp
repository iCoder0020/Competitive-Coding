/*
ID: iCoder0020
PROG: Validate Stack Sequences
LANG: C++                  
*/

 class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int n = pushed.size();
        int m = popped.size();
        if(n!=m) 
            return false;
        if (n == 0)
            return true;
        int i = 0, j = 0;
        stack<int>A;
        while(1)
        {
            while(i<n)
            {
                A.push(pushed[i]);
                i++;
                if(pushed[i-1] == popped[j])
                    break;
            }
            while(!A.empty() && A.top() == popped[j])
            {
                j++;
                A.pop();
            }
            if(i == n)
                break;
        }
        while(!A.empty())
        {
            if(A.top()!=popped[j])
                break;
            A.pop();
            j++;
        }
        return j==m;
    }
};    