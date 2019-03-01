/*
ID: ishan_sang
PROG: NSA
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	string S,S_rev,S_copy,S_rev_copy;
	long int X,Y,Y_copy;
	long int min;
	int starting_index;
	char max_letter;
	cin>>T;
	for(int t = 0; t<T; t++)
	{	
		cin>>S;
		int letters[2][S.length()][26];
		S_rev = "";

		for(int i = S.length()-1; i>=0; i--)
		{
			S_rev+=S[i];
		}

		Y = 0;

		min = S.length()*S.length();

		max_letter = 'a';
		for(int i = 0; i<S.length(); i++)
		{
			max_letter = (max_letter>S[i])?max_letter:S[i];
		}

		for(int i = 0; i<S.length(); i++)
		{
			for(int j = 0; j<26; j++)
			{
				letters[0][i][j] = 0;
				letters[1][i][j] = 0;
			}
		}

		for(int i = 0; i<S.length(); i++)
		{
			if(i == 0)
			{
				letters[0][i][int(S[i]-'a')]++;
			}
			else
			{
				for(int j = 0; j<26; j++)
				{
					letters[0][i][j] = letters[0][i-1][j];
				}
				letters[0][i][int(S[i]-'a')]++;
			}	
		}

		for(int i = 0; i<S_rev.length(); i++)
		{
			if(i == 0)
			{
				letters[1][i][int(S_rev[i]-'a')]++;
			}
			else
			{
				for(int j = 0; j<26; j++)
				{
					letters[1][i][j] = letters[1][i-1][j];
				}
				letters[1][i][int(S_rev[i]-'a')]++;
			}	
		}

		for(int i = 0; i<S.length(); i++)
		{
			for(int j = int(S[i]-'a')-1; j>=0; j--)
			{
				if(letters[0][i][j])
				{
					Y+=letters[0][i][j];
				}
			}
		}

		Y_copy = Y;

		for(starting_index = 0; starting_index<S.length(); starting_index++)
		{
			for(char c = 'a'; c<=max_letter; c++)
			{
				X = abs(int(c - S[starting_index]));
				Y = Y_copy;
				for(int j = int(S[starting_index]-'a')-1; j>=0; j--)
				{
					if(letters[0][starting_index][j])
					{
						Y-=letters[0][starting_index][j];
					}
				}
				letters[0][starting_index][int(S[starting_index] - 'a')]--;
				letters[0][starting_index][int(c - 'a')]++;
				for(int j = int(c-'a')-1; j>=0; j--)
				{
					if(letters[0][starting_index][j])
					{
						Y+=letters[0][starting_index][j];
					}
				}
				letters[0][starting_index][int(S[starting_index] - 'a')]++;
				letters[0][starting_index][int(c - 'a')]--;



				for(int j = int(S[starting_index]-'a')+1; j<26; j++)
				{
					if(letters[1][S.length()-1-starting_index][j])
					{
						Y-=letters[1][S.length()-1-starting_index][j];
					}
				}
				letters[1][S.length()-1-starting_index][int(S[starting_index] - 'a')]--;
				letters[1][S.length()-1-starting_index][int(c - 'a')]++;
				for(int j = int(c-'a')+1; j<26; j++)
				{
					if(letters[1][S.length()-1-starting_index][j])
					{
						Y+=letters[1][S.length()-1-starting_index][j];
					}
				}
				letters[1][S.length()-1-starting_index][int(S[starting_index] - 'a')]++;
				letters[1][S.length()-1-starting_index][int(c - 'a')]--;

				min = (min<X+Y)?min:X+Y;
			}
		}
		cout<<min<<"\n";
	}
	return 0;
}