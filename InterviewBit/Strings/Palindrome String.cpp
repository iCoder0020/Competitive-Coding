/*
ID: ishan-sang
PROG: Palindrome String
LANG: C++                  
*/

int Solution::isPalindrome(string A) 
{
    string S = "";
    for(auto it: A)
    {
        if(isalnum(it))
            S+=it;
    }
    if(S.length() == 0)
        return 1;
    for(int i = 0; i<S.length(); i++)
    {
        if(S[i]>='A' && S[i]<='Z')
            S[i]+=32;
    }
    int i = 0, j = S.length()-1;
    while(i<j)
    {
        if(S[i] != S[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
