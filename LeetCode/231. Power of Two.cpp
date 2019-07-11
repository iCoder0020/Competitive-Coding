/*
ID: iCoder0020
PROG: Power of Two
LANG: C++                  
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0 && ((n&(n-1)) == 0));
    }
};