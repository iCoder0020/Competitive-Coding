/*
ID: ishan-sang
PROG: Add Binary Strings
LANG: C++                  
*/

string Solution::addBinary(string A, string B) 
{
    if(B.length()>A.length())
    {
        string C = A;
        A = B;
        B = C;
    }
    string C(A.length(), '0');
    int m = A.length()-1;
    int carry = 0;
    int a = 0, b = 0, sum = 0;
    for(int n = B.length()-1; n>=0; n--)
    {
        a = A[m]-'0';
        b = B[n]-'0';
        sum = (a+b+carry)%2;
        carry = (a+b+carry)/2;
        C[m] = (char)(sum+'0');
        m--;
    }
    while(m>=0)
    {
        a = A[m]-'0';
        sum = (a+carry)%2;
        carry = (a+carry)/2;
        C[m] = (char)(sum+'0');
        m--;
    }
    if(carry)
        C = "1"+C;
    return C;
}
