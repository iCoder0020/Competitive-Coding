#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int TC;
	cin>>TC;
	while(TC--)
	{
		int K;
		cin>>K;
		vector<vector<char>>grid(8, vector<char>(8, 'X'));
		for(int i = 0; i<8; i++)
			for(int j = 0; j<8; j++)
				if(8*i+j<K)
					grid[i][j] = '.';
		grid[0][0] = 'O';
		for(int i = 0; i<8; i++)
		{
			for(int j = 0; j<8; j++)
				cout<<grid[i][j];
			cout<<endl;
		}
	}
	return 0;
}