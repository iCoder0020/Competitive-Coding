/*
ID: ishan_sang
PROG: SPELLBOB
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	char letters[2][3];
	bool possible;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		possible = false;
		for(int i = 0; i<2; i++)
		{
			for(int j = 0; j<3; j++)
			{
				cin>>letters[i][j];
			}
		}
		if((letters[0][0] == 'b' || letters[1][0] == 'b') && (letters[0][1] == 'o' || letters[1][1] == 'o') && (letters[0][2] == 'b' || letters[1][2] == 'b'))
		{
			possible = true;
		}
		if((letters[0][0] == 'b' || letters[1][0] == 'b') && (letters[0][1] == 'b' || letters[1][1] == 'b') && (letters[0][2] == 'o' || letters[1][2] == 'o'))
		{
			possible = true;
		}	
		if((letters[0][0] == 'o' || letters[1][0] == 'o') && (letters[0][1] == 'b' || letters[1][1] == 'b') && (letters[0][2] == 'b' || letters[1][2] == 'b'))
		{
			possible = true;
		}	
		if(possible)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	return 0;
}