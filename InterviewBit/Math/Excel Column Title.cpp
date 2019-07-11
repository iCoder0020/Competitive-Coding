/*
ID: ishan-sang
PROG: Excel Column Title
LANG: C++                  
*/

string Solution::convertToTitle(int A) 
{
    char arr[26];
    string ans = "";
    arr[0] = 'Z';
    for(int n = 1; n<26; n++)
        arr[n] = (char)('A'+n-1);
    while(A>0)
    {
        int rem = A%26;
        ans += arr[rem];
        A/=26;
        if(rem == 0)
            A--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
