/*
ID: iCoder0020
PROG: ACM ICPC Team
LANG: C++                  
*/

#include <iostream>

using namespace std;

int BITWISE_OR(char a, char b)
{
	int A = (int)(a) - 48;
	int B = (int)(b) - 48;
	return A|B;
}

int main()
{
	int contestants, subjects;
	cin>>contestants>>subjects;
	string S[contestants];
	int subject_count;
	int max_subject_count, max_team_count;
	for(int i = 0; i<contestants; i++)
	{
		cin>>S[i];
	}
	max_subject_count = 0;
	max_team_count = 0;
	for(int i = 0; i<contestants-1; i++)
	{
		for(int j = i+1; j<contestants; j++)
		{
			subject_count = 0;
			for(int k = 0; k<subjects; k++)
			{
				subject_count+=BITWISE_OR(S[i][k], S[j][k]);
			}
			if(subject_count > max_subject_count)
			{
				max_subject_count = subject_count;
				max_team_count = 1;
			}
			else if(subject_count == max_subject_count)
			{
				max_team_count++;
			}
			else
			{
				continue;
			}
		}
	}
	cout<<max_subject_count<<"\n"<<max_team_count<<"\n";
	return 0;
}