#include <bits/stdc++.h>

using namespace std;

#define int long long

void add_and_change(pair<int,int>p, vector<vector<char>>&A, vector<pair<int,int>>&moves)
{
	moves.push_back(p);
	int x = p.first, y = p.second;
	assert(x>=0 && x<A.size() && y>=0 && y<A[0].size());
	if(A[x][y] == '0')
		A[x][y] = '1';
	else
		A[x][y] = '0';
}

void p1(int i, int j, vector<vector<char>>&A, vector<pair<int,int>>&moves)
{
	add_and_change({i,j}, A, moves);
	add_and_change({i+1,j}, A, moves);
	add_and_change({i,j+1}, A, moves);
}

void p2(int i, int j, vector<vector<char>>&A, vector<pair<int,int>>&moves)
{
	add_and_change({i+1,j}, A, moves);
	add_and_change({i,j+1}, A, moves);
	add_and_change({i+1,j+1}, A, moves);
}
void p3(int i, int j, vector<vector<char>>&A, vector<pair<int,int>>&moves)
{
	add_and_change({i,j}, A, moves);
	add_and_change({i+1,j}, A, moves);
	add_and_change({i+1,j+1}, A, moves);
}

void p4(int i, int j, vector<vector<char>>&A, vector<pair<int,int>>&moves)
{
	add_and_change({i,j}, A, moves);
	add_and_change({i,j+1}, A, moves);
	add_and_change({i+1,j+1}, A, moves);
}

void zero(int i, int j, vector<vector<char>>&A, vector<pair<int,int>>&moves)
{
	p1(i+1,j+1,A,moves);
	p2(i+1,j+1,A,moves);
	p3(i+1,j+1,A,moves);
	p4(i+1,j+1,A,moves);
}

void one(int i, int j, vector<vector<char>>&A, vector<pair<int,int>>&moves)
{
	vector<pair<int,int>>ones;
	vector<pair<int,int>>zeros;
	for(int x = i; x<=i+1; x++)
	{
		for(int y = j; y<=j+1; y++)
		{
			if(A[x][y] == '0')
				zeros.push_back({x,y});
			else
				ones.push_back({x,y});
		}
	}
	if(zeros[0] == make_pair(i,j))
		p2(i,j,A,moves);
	else if(zeros[0] == make_pair(i,j+1))
		p3(i,j,A,moves);
	else if(zeros[0] == make_pair(i+1,j))
		p4(i,j,A,moves);
	else if(zeros[0] == make_pair(i+1,j+1))
		p1(i,j,A,moves);
}

void two(int i, int j, vector<vector<char>>&A, vector<pair<int,int>>&moves)
{
	vector<pair<int,int>>ones;
	vector<pair<int,int>>zeros;
	for(int x = i; x<=i+1; x++)
	{
		for(int y = j; y<=j+1; y++)
		{
			if(A[x][y] == '0')
				zeros.push_back({x,y});
			else
				ones.push_back({x,y});
		}
	}
	add_and_change(zeros[0], A, moves);
	add_and_change(zeros[1], A, moves);
	add_and_change(ones[0], A, moves);
	one(i,j,A,moves);
}

void three(int i, int j, vector<vector<char>>&A, vector<pair<int,int>>&moves)
{
	vector<pair<int,int>>ones;
	vector<pair<int,int>>zeros;
	for(int x = i; x<=i+1; x++)
	{
		for(int y = j; y<=j+1; y++)
		{
			if(A[x][y] == '0')
				zeros.push_back({x,y});
			else
				ones.push_back({x,y});
		}
	}
	add_and_change(zeros[0], A, moves);
	add_and_change(zeros[1], A, moves);
	add_and_change(ones[0], A, moves);
	two(i,j,A,moves);
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,M;
		cin>>N>>M;
		vector<vector<char>>A(N,vector<char>(M));
		for(int n = 0; n<N; n++)
			for(int m = 0; m<M; m++)
				cin>>A[n][m];
		vector<pair<int,int>>moves;
		for(int i = 0; i<N-1; i++)
		{
			for(int j = 0; j<M-1; j++)
			{
				vector<pair<int,int>>ones;
				vector<pair<int,int>>zeros;
				for(int x = i; x<=i+1; x++)
				{
					for(int y = j; y<=j+1; y++)
					{
						if(A[x][y] == '0')
							zeros.push_back({x,y});
						else
							ones.push_back({x,y});
					}
				}
				if(zeros.size() == 0)
					zero(i,j,A,moves);
				else if(zeros.size() == 1)
					one(i,j,A,moves);
				else if(zeros.size() == 2)
					two(i,j,A,moves);
				else if(zeros.size() == 3)
					three(i,j,A,moves);	

				if(j+1 != M-2)
					j++;
			}
			if(i+1 != N-2)
				i++;
		}
		cout<<moves.size()/3<<endl;
		for(pair<int,int>p: moves)
			cout<<p.first+1<<" "<<p.second+1<<" ";
		cout<<endl;
	}
	return 0;
}