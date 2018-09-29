/*
ID: ishansa2
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ofstream fout("palsquare.out");
ifstream fin("palsquare.in");

int B, i, j, digits;
char str[20], b[20];


void find_digits(int n)
{
	digits = 0;
	while (n != 0)
	{
		n /= B;
		digits++;
	}
}


char* change_base(int n)
{
	j = 0;
	find_digits(n);
	while (n != 0)
	{
		switch (n%B)
		{
		case 0:
			str[digits - j - 1] = '0';
			break;

		case 1:
			str[digits - j - 1] = '1';
			break;

		case 2:
			str[digits - j - 1] = '2';
			break;

		case 3:
			str[digits - j - 1] = '3';
			break;

		case 4:
			str[digits - j - 1] = '4';
			break;

		case 5:
			str[digits - j - 1] = '5';
			break;

		case 6:
			str[digits - j - 1] = '6';
			break;

		case 7:
			str[digits - j - 1] = '7';
			break;

		case 8:
			str[digits - j - 1] = '8';
			break;

		case 9:
			str[digits - j - 1] = '9';
			break;

		case 10:
			str[digits - j - 1] = 'A';
			break;

		case 11:
			str[digits - j - 1] = 'B';
			break;

		case 12:
			str[digits - j - 1] = 'C';
			break;

		case 13:
			str[digits - j - 1] = 'D';
			break;

		case 14:
			str[digits - j - 1] = 'E';
			break;

		case 15:
			str[digits - j - 1] = 'F';
			break;

		case 16:
			str[digits - j - 1] = 'G';
			break;

		case 17:
			str[digits - j - 1] = 'H';
			break;

		case 18:
			str[digits - j - 1] = 'I';
			break;

		case 19:
			str[digits - j - 1] = 'J';
			break;

		default:
			break;
		}
		j++;
		(n) /= B;
	}
	str[j] = '\0';
	return str;
}


char* reverse(char a[20], int n)
{
	find_digits(n);
	for (j = 0; a[j] != '\0'; j++)
	{
		b[j] = a[digits - j - 1];
	}
	b[j] = '\0';
	return b;
}

void check_palindrome(int n)
{
	int p = n*n;
	if (!strcmp(change_base(p), reverse(change_base(p), p)))
	{
		fout << change_base(n) << " ";
		fout<< change_base(p) << "\n";
	}
}

int main()
{
	fin >> B;
	for (i = 1; i <= 300; i++)
	{
	
		check_palindrome(i);
	}
	return 0;
}