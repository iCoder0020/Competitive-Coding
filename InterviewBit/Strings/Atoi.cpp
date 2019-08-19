/*
ID: ishan-sang
PROG: Atoi
LANG: C++                  
*/

int Solution::atoi(const string A) 
{
    long long int num = 0;
    string temp = "";
    for(auto it: A)
    {
        if( (it>='0' && it<='9' )|| (it == '-') || (it == '+') )
            temp += it;
        else 
            break;
    }
    if(temp == "")
        return 0;
    int N = temp.length();
    int start = (temp[0] == '-' || temp[0] == '+')?1:0;
    for(int n = start; n<N; n++)
    {
        num *= 10;
        if(temp[0] == '-')
            num-=(temp[n]-'0');
        else
            num+=(temp[n]-'0');
    }
    if(temp[0] == '-' && (num<INT_MIN || N>=11))
        num = INT_MIN;
    if(temp[0] != '-' && (num>INT_MAX || N>=10))
        num = INT_MAX;
    return num;
}
