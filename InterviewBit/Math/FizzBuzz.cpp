/*
ID: ishan-sang
PROG: FizzBuzz
LANG: C++                  
*/

vector<string> Solution::fizzBuzz(int A) {
    vector<string> ans(A);
    for(int n = 1; n<=A; n++)
    {
        string s = "";
        if(n%15 == 0)
            s = "FizzBuzz";
        else if(n%3 == 0)
            s = "Fizz";
        else if(n%5 == 0)
            s = "Buzz";
        else
        {
            int m = n;
            while(n)
            {
                s += (char)(n%10 + 48);
                n/=10;
            }
            n = m;
            reverse(s.begin(), s.end());
        }
        ans[n-1] = s;
    }
    return ans;
}

