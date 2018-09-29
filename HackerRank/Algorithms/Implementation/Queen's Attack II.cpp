/*
ID: iCoder0020
PROG: Queen's Attack II
LANG: C++                  
*/

#include <iostream>

using namespace std;

struct position
{
	int x;
	int y;
};

int min(int a, int b)
{
	return (a<b)?a:b;
}

int max(int a, int b)
{
	return (a>b)?a:b;
}

void set_queen_limits(int X, int Y, position nearest_obstacles[8], int N)
{
	nearest_obstacles[0].x = X;
	nearest_obstacles[0].y = N+1;

	nearest_obstacles[4].x = X;
	nearest_obstacles[4].y = 0;

	nearest_obstacles[2].x = N+1;
	nearest_obstacles[2].y = Y;

	nearest_obstacles[6].x = 0;
	nearest_obstacles[6].y = Y;

	if(X == Y)
	{
		nearest_obstacles[1].x = N+1;
		nearest_obstacles[1].y = N+1;

		nearest_obstacles[5].x = 0;
		nearest_obstacles[5].y = 0;
 	}
 	else if(X<Y)
 	{
 		nearest_obstacles[1].x = N-(Y-X)+1;
 		nearest_obstacles[1].y = N+1;

 		nearest_obstacles[5].x = 0;
 		nearest_obstacles[5].y = (Y-X);
 	}
 	else
 	{
 		nearest_obstacles[1].x = N+1;
 		nearest_obstacles[1].y = N+(Y-X)+1;

 		nearest_obstacles[5].x = -(Y-X);
 		nearest_obstacles[5].y = 0;
 	}

	if(X + Y == N+1)
	{
		nearest_obstacles[3].x = N+1;
		nearest_obstacles[3].y = 0;

		nearest_obstacles[7].x = 0;
		nearest_obstacles[7].y = N+1;
 	}
 	else if((X<=N/2) && (Y<=N/2))
 	{
 		nearest_obstacles[3].x = Y+X;
		nearest_obstacles[3].y = 0;

		nearest_obstacles[7].x = 0;
		nearest_obstacles[7].y = Y+X;
 	}
 	else
 	{
 		nearest_obstacles[3].x = N+1;
		nearest_obstacles[3].y = (Y+X)-(N+1);

		nearest_obstacles[7].x = (Y+X)-(N+1);
		nearest_obstacles[7].y = N+1;
 	}
}

int main()
{
	int N,K;
	cin>>N>>K;
	position queen_position;
	cin>>queen_position.x>>queen_position.y;
	position obstacle_position[K];
	position nearest_obstacles[8];
	set_queen_limits(queen_position.x, queen_position.y, nearest_obstacles, N);
	long int count_squares = 0;

	for(int i = 0; i<K; i++)
	{
		cin>>obstacle_position[i].x>>obstacle_position[i].y;
		if(queen_position.x == obstacle_position[i].x)
		{
			if(queen_position.y < obstacle_position[i].y)
			{
				nearest_obstacles[0].x = obstacle_position[i].x;
				nearest_obstacles[0].y = min(obstacle_position[i].y, nearest_obstacles[0].y);
			}
			if(queen_position.y > obstacle_position[i].y)
			{
				nearest_obstacles[4].x = obstacle_position[i].x;
				nearest_obstacles[4].y = max(obstacle_position[i].y, nearest_obstacles[4].y);
			}
		}


		if(queen_position.y == obstacle_position[i].y)
		{
			if(queen_position.x < obstacle_position[i].x)
			{
				nearest_obstacles[2].x = min(obstacle_position[i].x, nearest_obstacles[2].x);
				nearest_obstacles[2].y = obstacle_position[i].y;
			}
			if(queen_position.x > obstacle_position[i].x)
			{
				nearest_obstacles[6].x = max(obstacle_position[i].x, nearest_obstacles[6].x);
				nearest_obstacles[6].y = obstacle_position[i].y;
			}
		}


		if(queen_position.y - queen_position.x == obstacle_position[i].y - obstacle_position[i].x)
		{
			if(queen_position.x < obstacle_position[i].x && queen_position.y < obstacle_position[i].y)
			{
				nearest_obstacles[1].x = min(obstacle_position[i].x, nearest_obstacles[1].x);
				nearest_obstacles[1].y = min(obstacle_position[i].y, nearest_obstacles[1].y);
			}
			if(queen_position.x > obstacle_position[i].x && queen_position.y > obstacle_position[i].y)
			{
				nearest_obstacles[5].x = max(obstacle_position[i].x, nearest_obstacles[5].x);
				nearest_obstacles[5].y = max(obstacle_position[i].y, nearest_obstacles[5].y);
			}
		}


		if(queen_position.y + queen_position.x == obstacle_position[i].y + obstacle_position[i].x)
		{
			if(queen_position.x < obstacle_position[i].x && queen_position.y > obstacle_position[i].y)
			{
				nearest_obstacles[3].x = min(obstacle_position[i].x, nearest_obstacles[3].x);
				nearest_obstacles[3].y = min(obstacle_position[i].y, nearest_obstacles[3].y);
			}
			if(queen_position.x > obstacle_position[i].x && queen_position.y < obstacle_position[i].y)
			{
				nearest_obstacles[7].x = max(obstacle_position[i].x, nearest_obstacles[7].x);
				nearest_obstacles[7].y = max(obstacle_position[i].y, nearest_obstacles[7].y);
			}
		}
	}

	for(int i = 0; i<8; i++)
	{
		if(i == 0 || i == 4)
		{
			count_squares += abs(queen_position.y - nearest_obstacles[i].y) - 1;
		}
		else
		{
			count_squares += abs(queen_position.x - nearest_obstacles[i].x) - 1;
		}
	}
	cout<<count_squares<<"\n";
	return 0;
}