#ID: f20170069
#PROG: Python If-Else
#LANG: Python

N=(int)(input())

if(N%2==1):
	print("Weird")
else:
	if(N>=2 and N<=5 or N>20):
		print("Not Weird")
	else:
		print("Weird")