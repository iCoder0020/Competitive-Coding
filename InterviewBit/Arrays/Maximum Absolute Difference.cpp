/*
ID: ishan-sang
PROG: Maximum Absolute Difference
LANG: C++                  
*/

int Solution::maxArr(vector<int> &A) 
{
    int N = A.size();
    vector<int> arr1(N);
    vector<int> arr2(N);
    for(int i = 0; i<N; i++)
    {
        arr1[i] = A[i] + i;
        arr2[i] = A[i] - i;
    }
    int ans = 0;
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int a = arr1[0];
    int b = arr1[N-1];
    int c = arr2[0];
    int d = arr2[N-1];
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    ans = max(ans, d-a);
    ans = max(ans, d-c);
    ans = max(ans, b-a);
    ans = max(ans, b-c);
    return ans;
}
