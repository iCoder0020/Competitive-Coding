/*
ID: ishan-sang
PROG: N/3 Repeat Number
LANG: C++                  
*/

int Solution::repeatedNumber(const vector<int> &A) 
{
    int N = A.size();
    int K = 0;
    int num1 = -1, num2 = -1;
    int cnt1 = 0, cnt2 = 0;
    for(auto it: A)
    {
        if(num1 == it)
            cnt1++;
        else if(num2 == it)
            cnt2++;
        else if(cnt1 == 0)
        {
            num1 = it;
            cnt1 = 1;
        }
        else if(cnt2 == 0)
        {
            num2 = it;
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(auto it: A)
    {
        if(it == num1)
            cnt1++;
        if(it == num2)
            cnt2++;
    }
    if(cnt1 >= cnt2 && cnt1 > N/3)
        return num1;
    else if(cnt2 > N/3)
        return num2;
    return -1;
}
