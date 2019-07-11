/*
ID: iCoder0020
PROG: Palindrome Number
LANG: C++                  
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long int n = 0;
        long long int y = x; 
        while(x)
        {
            n = n*10 + x%10;
            x/=10;
        }
        return (n==y);
    }
};