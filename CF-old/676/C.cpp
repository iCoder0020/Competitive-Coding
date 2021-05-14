#include <bits/stdc++.h>

using namespace std;

#define int long long

int N;
string S;
vector<pair<char,int>>moves;

void move(char c, int x)
{
	if(c == 'L')
		moves.push_back({c, x+1});
	else
		moves.push_back({c, S.length()-x});
	string T;
	if(c == 'L')
		T = S.substr(1, x);
	else
		T = S.substr(S.length()-1-x, x);
	reverse(T.begin(), T.end());
	if(c == 'L')
		S = T+S;
	else
		S = S+T;
	// cout<<S<<endl;
}

bool is_palindrome()
{
	for(int i = 0; i<N; i++)
		if(S[i] != S[S.length()-1-i])
			return false;
	return true;
}

int32_t main()
{
	cin>>S;
	N = S.length();
	move('L', N-2);
	move('R', N-2);
	move('L', N-2);
	move('L', 3*N-6+1);
	move('L', N-2);
	cout<<moves.size()<<endl;
	for(pair<char,int> m: moves)
		cout<<m.first<<" "<<m.second<<endl;
	return 0;
}