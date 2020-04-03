/*
ID: ishansa2
PROG: pprime
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

ofstream fout("pprime.out");
ifstream fin("pprime.in");

#define int long long
#define INF 1LL<<32

int A,B;
vector<int>ans;

// string to_string(int x)
// {
// 	string s;
// 	while(x)
// 	{
// 		s = ((x%10) + '0') + s;
// 		x /= 10;
// 	}
// 	return s;
// }

void solve(int x, int i)
{
	if(x>=A && x<=B)
	{
		bool push = true;
		for(int j = 2; j*j<=x; j++)
		{
			if(x%j == 0)
			{
				push = false;
				break;
			}
		}
		if(push)
			ans.push_back(x);
	}
	if(x>B)
		return;
	string s = to_string(x);
	if(i&1)
	{
		for(int j = 0; j<=9; j++)
		{
			char c = (j+'0');
			string t = s.substr(0, (i+1)/2) + c + s.substr((i+1)/2, (i+1)/2);
			// cout<<"odd"<<s<<" "<<t<<endl;
			solve(stoi(t), i+1);
		}
	}
	else
	{
		string t = s.substr(i/2,1);
		t = s.substr(0, i/2) + t + s.substr(i/2, i/2+1);
		// cout<<"even"<<s<<" "<<t<<endl;
		solve(stoi(t), i+1);
	}
}

int32_t main()
{
 	fin>>A>>B;
 	for(int i = 1; i<=9; i++)
 		solve(i, 0);
 	sort(ans.begin(), ans.end());
 	for(auto it: ans)
 		fout<<it<<endl;
    return 0;
}