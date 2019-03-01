/*
ID: iCoder0020
PROG: Yuhao and a Parenthesis
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int count(string S)
{
	int cnt = 0;
	for(auto it: S)
	{
		if(it == '(')
		{
			cnt++;
		}
		else
		{
			cnt--;
		}
	}
	return cnt;
}

string reduce(string S)
{
	stack<char>st;
	string T = "";
	for(auto it: S)
	{
		if(st.empty())
		{
			st.push(it);
			T+=it;
		}
		else
		{
			if(it == '(')
			{
				st.push(it);
				T+=it;
			}
			else
			{
				if(st.top() == '(')
				{
					st.pop();
					T.pop_back();
				}
				else
				{
					st.push(it);
					T+=it;
				}
			}
		}
	}
	return T;
}

int main()
{
	int N;
	cin>>N;
	string S;
	multiset<int> types[3];
	int valid = 0;
	int ans = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>S;
		S = reduce(S);
		int last = S.length()-1;
		int cnt = count(S);
		if(S == "")
		{
			valid++;
		}
		else if(S[0] == '(' && S[last] == '(')
		{
			types[0].insert(cnt);
		}
		else if(S[0] == '(' && S[last] == ')')
		{
			types[1].insert(cnt);
		} 
		else if(S[0] == ')' && S[last] == ')')
		{
			types[2].insert(cnt);
		}
	}
	ans += valid/2;

	for(auto it1 = types[1].begin(); it1!=types[1].end(); it1++)
	{
		int diff = *it1;
		auto it2 = types[1].find(-1*diff);
		if(it2 != types[1].end())
		{
			types[1].erase(it1);
			types[1].erase(it2);
			ans++;
		}
	}

	for(auto it1 = types[0].begin(); it1!=types[0].end(); it1++)
	{
		int diff = *it1;
		auto it2 = types[1].find(-1*diff);
		if(it2 != types[1].end())
		{
			types[0].erase(it1);
			types[1].erase(it2);
			ans++;
			continue;
		}
		auto it3 = types[2].find(-1*diff);
		if(it3 != types[2].end())
		{
			types[0].erase(it1);
			types[2].erase(it3);
			ans++;
		}
	}

	for(auto it1 = types[2].begin(); it1!=types[2].end(); it1++)
	{
		int diff = *it1;
		auto it2 = types[1].find(-1*diff);
		if(it2 != types[1].end())
		{
			types[2].erase(it1);
			types[1].erase(it2);
			ans++;
			continue;
		}
		auto it3 = types[0].find(-1*diff);
		if(it3 != types[0].end())
		{
			types[2].erase(it1);
			types[0].erase(it3);
			ans++;
		}
	}

	cout<<ans<<endl;
	return 0;
}