/*
ID: ishan-sang
PROG: Colorful Number
LANG: C++                  
*/

int Solution::colorful(int A) 
{
    int A_copy = A;
    int num_dig = 0;
    vector<int>nums(10, 0);
    unordered_map<int,int> MAP;
    while(A_copy)
    {
        nums[A_copy%10]++;
        A_copy/=10;
        num_dig++;
    }
    if(num_dig == 1)
        return 1;
    if(nums[0] || nums[1])
        return 0;
    for(int n = 2; n<=9; n++)
        if(nums[n] > 1)
            return 0;
    string S = to_string(A);
    for(int n = 1; n<=num_dig; n++)
    {
        for(int i = 0; i<=num_dig-n; i++)
        {
            int x = stoi(S.substr(i, n));
            int p = 1;
            while(x)
            {
                p *= (x%10);
                x/=10;
            }
            if(MAP.find(p) != MAP.end())
                return 0;
            MAP[p] = 1;
        }
    }
    return 1;
}
