/*
ID: ishan-sang
PROG: Generate all Parentheses
LANG: C++                  
*/

int Solution::isValid(string A) 
{
    int cnt[3] = {0};
    for(auto it: A)
    {
        if(it == '(')
            cnt[0]++;
        else if(it == ')')
            cnt[0]--;
        else if(it == '{')
            cnt[1]++;
        else if(it == '}')
            cnt[1]--;
        else if(it == '[')
            cnt[2]++;
        else
            cnt[2]--;
        if(cnt[1]<0 || cnt[1]<0 || cnt[2]<0)
            return 0;
    }
    if(cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0)
        return 1;
    return 0;
}
