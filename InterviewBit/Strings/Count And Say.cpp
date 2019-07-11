/*
ID: ishan-sang
PROG: Count And Say
LANG: C++                  
*/

string Solution::countAndSay(int A) 
{
    int cnt = 1;
    int count;
    string prev = "1";
    while(cnt < A)
    {
        string next = "";
        for(int i = 0; i<prev.size();)
        {
            char ch = prev[i];
            int count = 0;
            while(i<prev.size() && ch == prev[i])
            {
                count++;
                i++;
            }
            next+=to_string(count);
            next+=ch;
        }
        prev = next;
        cnt++;
    }
    return prev;
}
