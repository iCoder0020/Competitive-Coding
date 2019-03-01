/*
ID: ishan_sang
PROG: BINIM2
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int remove_continous_from_top(string &S, char c)
{
  int index = 0;
  for(int i = 0; i<S.length(); i++)
  {
    if(S[i] != c)
    {
      index = i;
      break;
    }
    else
    {
      S[i] = ' ';
    }
  }

  for(int i = 0; i<S.length()-index; i++)
  {
    S[i] = S[i+index];
  }
  for(int i = 0; i<index; i++)
  {
    S.pop_back();
  }
  return index; 
}

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N;
		string starting_player;
		cin>>N>>starting_player;

		string B[N];
		int zero_count[N] = {0};
		int one_count[N] = {0};

		for(int n = 0; n<N; n++)
		{
			cin>>B[n];
			for(int m = 0; m<B[n].length(); m++)
			{
				if(B[n][m] == '0')
				{
					zero_count[n]++;
				}
				else
				{
					one_count[n]++;
				}
			}
		}

		int turn = 0; 
		bool game_over = false;

		while(true)
		{
			if(((turn%2 == 0 && starting_player.compare("Dee")) == 0) || (turn%2 == 1 && starting_player.compare("Dum")))
			{
				int index_with_1 = -1;
				for(int n = 0; n<N; n++)
				{
					if(B[n][0] == '0' && one_count[n] != 0)
					{
						index_with_1 = n;
					}
					if(B[n][0] == '1')
					{
						index_with_1 = 5;
						break;
					}
					else if(n == N-1)
					{
						if(index_with_1 == -1)
						{
							cout<<"Dum\n";
							game_over = true;
							break;
						}
						else
						{
							zero_count[index_with_1] -= remove_continous_from_top(B[index_with_1], '0');
						}
					}
				}
				if(index_with_1 == 5)
				{
					int max_count = 0;
					int index = -1;
					for(int n = 0; n<N; n++)
					{
						if(B[n][0] == '0' && zero_count[n]>max_count)
						{
							index = n;
							max_count = zero_count[n];
						}
					}
					if(index == -1)
					{
						cout<<"Dee\n";
						game_over = true;
						break;
					}
					else
					{
						zero_count[index] -= remove_continous_from_top(B[index], '0');
					}
				}
			}

			else
			{
				int index_with_0 = -1;
				for(int n = 0; n<N; n++)
				{
					if(B[n][0] == '1' && zero_count[n] != 0)
					{
						index_with_0 = n;
					}
					if(B[n][0] == '0')
					{
						index_with_0 = 5;
						break;
					}
					else if(n == N-1)
					{
						if(index_with_0 == -1)
						{
							cout<<"Dee\n";
							game_over = true;
							break;
						}
						else
						{
							one_count[index_with_0] -= remove_continous_from_top(B[index_with_0], '1');
						}
					}
				}
				if(index_with_0 == 5)
				{
					int max_count = 0;
					int index = -1;
					for(int n = 0; n<N; n++)
					{
						if(B[n][0] == '1' && one_count[n]>max_count)
						{
							index = n;
							max_count = one_count[n];
						}
					}
					if(index == -1)
					{
						cout<<"Dum\n";
						game_over = true;
						break;
					}
					else
					{
						one_count[index] -= remove_continous_from_top(B[index], '1');
					}
				}
			}

			if(game_over)
			{
				break;
			}
			turn++;
		}
	}
	return 0;
}