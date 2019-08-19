/*
ID: ishan-sang
PROG: Sum Of Fibonacci Numbers
LANG: C++                  
*/

int Solution::fibsum(int A) 
{
    int a = 1, b = 1, c = 2;
    vector<int> fib = {1};
    while(c<=A)
    {
        fib.push_back(c);
        a = b;
        b = c;
        c = a+b;
    }
    set<int> ans;
    int num = 0;
    while(1)
    {
        if(num == A)
            break;
        int i = lower_bound(fib.begin(), fib.end(), A-num) - fib.begin();
        if(fib[i] != A-num)
            i--;
        num += fib[i];
        ans.insert(fib[i]);
    }
    return ans.size();
}
