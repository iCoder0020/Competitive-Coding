/*
ID: ishan-sang
PROG: Palindrome Integer
LANG: C++                  
*/

int Solution::isPalindrome(int A) 
{
    if(A<0)
        return 0;
    int B = 0;
    int A_copy = A;
    while(A_copy)
    {
        B = 10*B + A_copy%10;
        A_copy /= 10;
    }
    return (A == B);
}

