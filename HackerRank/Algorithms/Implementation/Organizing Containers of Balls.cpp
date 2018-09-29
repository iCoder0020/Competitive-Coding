/*
ID: iCoder0020
PROG: Organizing Containers of Balls
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int Q;
	int N;
	int min;
	string answer;
	cin>>Q;
	for(int q = 0; q<Q; q++)
	{
		cin>>N;
		int num_balls[N][N];
		for(int container = 0; container<N; container++)
		{
			for(int type = 0; type<N; type++)
			{
				cin>>num_balls[container][type];
			}
		}
		for(int container = 0; container<N-1; container++)
		{
			for(int type = container+1; type<N; type++)
			{
				if(num_balls[container][type] == 0)
				{
					continue;
				}
				else
				{
					for(int second_container = container+1; second_container<N; second_container++)
					{
						if(num_balls[second_container][container] != 0)
						{
							if(num_balls[container][type]<=num_balls[second_container][container])
							{
								num_balls[container][container] += num_balls[container][type];
								num_balls[second_container][type] += num_balls[container][type];
								num_balls[second_container][container] -= num_balls[container][type];
								num_balls[container][type] = 0;
							}
							else
							{
								num_balls[container][container] += num_balls[second_container][container];
								num_balls[second_container][type] += num_balls[second_container][container];
								num_balls[container][type] -= num_balls[second_container][container];
								num_balls[second_container][container] = 0;
							}	
						}					
					}
				}
			}
		}
		for(int container = 0; container<N; container++)
		{
			for(int type = 0; type<N; type++)
			{
				if(num_balls[container][type] != 0 && type != container)
				{
					answer = "Impossible";
					break;
				}
				if(num_balls[container][type] == 0 && type == N-1)
				{
					answer = "Possible";
				}
			}
			if(answer == "Impossible")
			{
				break;
			}
		}
		cout<<answer<<"\n";
	}
	return 0;
}