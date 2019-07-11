/*
ID: iCoder0020
PROG: Ugly Number II
LANG: C++                  
*/

class Solution {
public:
    int nthUglyNumber(int x) {
        int ans[1691];
        int n =  2;
        int i = 1, j = 1, k = 1;
        ans[1] = 1;
        while(n<=x)
        {
            int x1 = 2*ans[i];
            int x2 = 3*ans[j];
            int x3 = 5*ans[k];
            ans[n] = min(x1, min(x2,x3));
            if(x1 == ans[n])
                i++;
            if(x2 == ans[n])
                j++;
            if(x3 == ans[n])
                k++;
            n++;
        }
        return ans[x];
    }
};