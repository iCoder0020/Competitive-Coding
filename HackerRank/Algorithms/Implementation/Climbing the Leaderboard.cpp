/*
ID: iCoder0020
PROG: Climbing the Leaderboard
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int total_games;
	int games_played;
	cin>>total_games;
	int leaderboard[total_games];
	int ranking[total_games];
	for(int i = 0; i<total_games; i++)
	{
		cin>>leaderboard[i];
		if(i == 0)
		{
			ranking[i] = 1;
		}
		else
		{
			if(leaderboard[i] == leaderboard[i-1])
			{
				ranking[i] = ranking[i-1];
			}
			else
			{
				ranking[i] = ranking[i-1] + 1;
			}
		}
	}
	cin>>games_played;
	int alice_score;
	int min_index, mid_index, max_index;
	min_index = 0;
	max_index = total_games - 1;
	for(int i = 0; i<games_played; i++)
	{
		cin>>alice_score;
		if(alice_score >= leaderboard[0])
		{
			cout<<ranking[0]<<"\n";
			max_index = 0;
			continue;
		}
		if(alice_score == leaderboard[total_games - 1])
		{
			cout<<ranking[total_games - 1]<<"\n";
			max_index = total_games - 1;
			continue;
		}
		if(alice_score < leaderboard[total_games - 1])
		{
			cout<<ranking[total_games - 1] + 1<<"\n";
			max_index = total_games - 1;
			continue;
		}
		while(1)
		{
			mid_index = (min_index + max_index)/2;
			if(leaderboard[mid_index] == alice_score)
			{
				cout<<ranking[mid_index]<<"\n";
				max_index = mid_index;
				break;
			}
			if(leaderboard[mid_index]>alice_score && leaderboard[mid_index+1]<alice_score)
			{
				cout<<ranking[mid_index] + 1<<"\n";
				max_index = mid_index;
				break;
			}
			if(leaderboard[mid_index]<alice_score && leaderboard[mid_index-1]>alice_score)
			{
				cout<<ranking[mid_index]<<"\n";
				max_index = mid_index;
				break;
			}
			if(leaderboard[mid_index]>alice_score)
			{
				min_index = mid_index + 1;
			}
			if(leaderboard[mid_index]<alice_score)
			{
				max_index = mid_index - 1;
			}
		}
		min_index = 0;
	}
	return 0;
}